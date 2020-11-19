
/* 
 * This file is part of OSMM module and header of RequestAnalyzer submodule.
 *
 * Developed for the OpenStreet Data Management System.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 */

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "RequestAnalyzer.h"
#include "OverpassAPI.h"
#include "PriorKnowledgeProvider.h"

 /**
 * Process JSON data.
 *
 * @param json_data contains JSON object array.
 * @return array of road description
 *
 * @exceptsafe This function does not throw exceptions.
 */
vector<RoadPart> RequestAnalyzer::Process(const OSMModuleRequest& request, const vector<JSONValue*>& json_data)
{
	PriorKnowledgeProvider priorKnowledgeProvider;
	int global_lane_id = 0;

	vector<RoadPart> result;
	result.reserve(json_data.size() * 4);

	for (int i = 0; i < json_data.size(); i++)
	{
		if (json_data[i] == 0)
			continue;

		JSONArray elements = json_data[i]->AsArray();

		for (size_t j = 0; j < elements.size(); j++)
		{
			JSONObject way = elements[j]->AsObject();
	
			RoadPart road_part;

			road_part.pos = request.poses[i];

			JSONArray geometry = way[L"geometry"]->AsArray();

			LatLon coord(geometry[0]);

			JSONObject tags = way[L"tags"]->AsObject();

			//====================================================
			if (tags[L"name"] != NULL)
				road_part.name = tags[L"name"]->AsString();

			cout << "Getting country name by Overpass API ..." << endl;
			road_part.country = OverpassAPI::GetCountryName(coord); // SLR3

			if (tags[L"highway"] != NULL)
				road_part.highway = tags[L"highway"]->AsString();

			// SLR4
			if (tags[L"width"] != NULL)
				road_part.width = (int)tags[L"width"]->AsIntegerFromString();
			//else // TODO: needed ?
			//	road_part.width = priorKnowledgeProvider.GetWayWidth(road_part.country, road_part.highway);

			// SLR4
			if (tags[L"maxspeed"] != NULL)
				road_part.maxspeed = (int)tags[L"maxspeed"]->AsIntegerFromString();
			//else // TODO: needed ?
			//	road_part.maxspeed = priorKnowledgeProvider.GetMaxSpeed(road_part.country, road_part.highway);

			if (tags[L"maxheight"] != NULL)
				road_part.maxheight = (int)tags[L"maxheight"]->AsIntegerFromString();

			if (tags[L"maxwidth"] != NULL)
				road_part.maxwidth = (int)tags[L"maxwidth"]->AsIntegerFromString();

			if (tags[L"maxweight"] != NULL)
				road_part.maxweight = (int)tags[L"maxweight"]->AsIntegerFromString();

			// SLR4
			if (tags[L"lanes"] != NULL)
				road_part.lane_count = tags[L"lanes"]->AsIntegerFromString();
			else
				road_part.lane_count = priorKnowledgeProvider.GetLaneCount(road_part.country, road_part.highway);

			if (tags[L"oneway"] != NULL)
				road_part.oneway = tags[L"oneway"]->AsString();

			if (tags[L"junction"] != NULL)
				road_part.junction = tags[L"junction"]->AsString();

			//====================================================
			if (tags[L"lit"] != NULL)
				road_part.lit = tags[L"lit"]->AsString();

			if (tags[L"smoothness"] != NULL)
				road_part.smoothness = tags[L"smoothness"]->AsString();

			if (tags[L"surface"] != NULL)
				road_part.surface = tags[L"surface"]->AsString();
			
			if (tags[L"source"] != NULL)
				road_part.source = tags[L"source"]->AsString();

			if (tags[L"source:maxspeed"] != NULL)
				road_part.source_maxspeed = tags[L"source:maxspeed"]->AsString();

			//====================================================
			if (tags[L"access"] != NULL)
				road_part.access = tags[L"access"]->AsString();

			if (tags[L"bicycle"] != NULL)
				road_part.bicycle = tags[L"bicycle"]->AsString();

			if (tags[L"foot"] != NULL)
				road_part.foot = tags[L"foot"]->AsString();

			if (tags[L"footway"] != NULL)
				road_part.footway = tags[L"footway"]->AsString();
			
			//====================================================
			// SLR5
			// TODO: can be center of line segments, but now, center of bound
			JSONObject bounds = way[L"bounds"]->AsObject();
			road_part.center_coord = LatLon((bounds[L"minlat"]->AsNumber() + bounds[L"maxlat"]->AsNumber()) / 2,
				(bounds[L"minlon"]->AsNumber() + bounds[L"maxlon"]->AsNumber()) / 2);

			//====================================================
			road_part.lane_sections.resize(1);

			LaneSection& lane_section = road_part.lane_sections[0];
			lane_section.lanes.resize(road_part.lane_count);

			for (size_t k = 0; k < lane_section.lanes.size(); k++)
			{
				Lane& lane = lane_section.lanes[k];
				lane.id = ++global_lane_id;
				lane.previous_id = -1;
				lane.next_id = -1;
				lane.maxspeed = road_part.maxspeed;
				lane.width = priorKnowledgeProvider.GetLaneWidth(road_part.country, road_part.highway);
				lane.lateral_offset = 0; // must be calculated later

				// SLR6
				lane.driving_direction = POSITIVE;
				lane.left_marking = priorKnowledgeProvider.GetLeftMarking(road_part.country, road_part.highway);
				lane.right_marking = priorKnowledgeProvider.GetRightMarking(road_part.country, road_part.highway);
				lane.left_marking_color = priorKnowledgeProvider.GetLeftMarkingColor(road_part.country, road_part.highway);
				lane.right_marking_color = priorKnowledgeProvider.GetRightMarkingColor(road_part.country, road_part.highway);
			}

			vector<VehiclePos>& chord_coords = lane_section.chord_coords;
			chord_coords.resize(geometry.size());

			for (size_t k = 0; k < geometry.size(); k++)
			{
				VehiclePos& pos = chord_coords[k];
				pos.coord = LatLon(geometry[k]);
				pos.heading = road_part.pos.heading;
			}

			//====================================================
			cout << "Getting nodes around way by Overpass API ..." << endl;
			JSONValue* way_nodes_json = OverpassAPI::GetNodesData(chord_coords);
			if (way_nodes_json != 0)
			{
				JSONArray node_elements = way_nodes_json->AsArray();
				lane_section.way_nodes.resize(node_elements.size());

				for (size_t k = 0; k < node_elements.size(); k++)
					lane_section.way_nodes[k].ParseFromOSMJson(node_elements[k]);

				delete way_nodes_json;
			}

			result.push_back(road_part);
		}
	}

	return result;
}
