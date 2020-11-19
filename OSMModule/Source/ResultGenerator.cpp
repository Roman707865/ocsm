/* 
 * This file is part of OSMM module and header of ResultGenerator submodule.
 * Developed for the OpenStreet Data Management System.
 * This is submodule for complete OSMModuleRequestResult.
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


#include "ResultGenerator.h"
#include <iostream>
#include <fstream>

#define JSON_PATH				"Results.json"

 /**
  * Complete result of OSM module request.
  *
  * @param values contain number of sub requests.
  * @return completed OSMModuleRequestResult object pointer.
  *
  * @exceptsafe This function does not throw exceptions.
  */
OSMModuleRequestResult ResultGenerator::Process(size_t sub_requests, vector<RoadPart>& road_parts)
{
	this->road_parts = road_parts;

	return Process();
}
OSMModuleRequestResult ResultGenerator::Process()
{
	cout << "======== Generating result... ========" << endl;

	OSMModuleRequestResult res;

	if (this->road_parts.empty())
	{
		res.request_status = NOTFOUND;
	}
	else
	{
		res.request_status = SUCCESS;
	}

	res.road_parts = this->road_parts;

	return res;
}

/* append result */
void ResultGenerator::Append(RoadPart& road_part)
{
	this->road_parts.push_back(road_part);
};

/* output with JSON format */
void ResultGenerator::JsonParserOutput()
{
	wfstream fout;

	fout.open(JSON_PATH, ios::out);

	JSONParserOutputTempl(fout);

	fout.close();
};

template <class _Elem, class _Traits>
void ResultGenerator::JSONParserOutputTempl(basic_ostream< _Elem, _Traits>& stream)
{
	stream << L"[";

	for (int i = 0; i < this->road_parts.size(); i++)
	{
		stream << endl;

		JSONValue* obj = this->road_parts[i].ToJSONObject();

		stream << obj->Stringify(true);

		delete obj;

		if (i != this->road_parts.size() - 1)
			stream << L",";
	}

	stream << endl << L"]" << endl;
}

/**
* Search lane properties and add it on OSMModuleRequestResult.
*
* @param value contain OSMModuleRequestResult object pointer.
* @return OSMModuleRequestResult object pointer .
*
* @exceptsafe This function does not throw exceptions.
*/
/*
OSMModuleRequestResult& Output1(OSMModuleRequestResult& res)
{
	int k_id = 0;

	vector<RoadPart>& roadpart = res.road_parts;

	for (int j = 0; j < res.road_parts.size(); j++)
	{
		if (j > 0 && j < res.road_parts.size() - 1)
		{

			for (size_t k = 0; k < roadpart[j].lane_sections[0].lanes.size(); k++)
			{
				for (size_t m = 0; m < roadpart[j - 1].lane_sections[0].lanes.size(); m++)
				{
					if (roadpart[j].lane_sections[0].lanes[k].driving_direction ==
						roadpart[j - 1].lane_sections[0].lanes[m].driving_direction)
					{
						roadpart[j].lane_sections[0].lanes[m].previous_id = roadpart[j - 1].lane_sections[0].lanes[m].id;
					}
				}
			}

			for (size_t k = 0; k < roadpart[j].lane_sections[0].lanes.size(); k++)
			{
				for (size_t m = 0; m < roadpart[j + 1].lane_sections[0].lanes.size(); m++)
				{
					if (roadpart[j].lane_sections[0].lanes[k].driving_direction ==
						roadpart[j + 1].lane_sections[0].lanes[m].driving_direction)
					{
						roadpart[j].lane_sections[0].lanes[m].next_id = roadpart[j + 1].lane_sections[0].lanes[m].id;
					}
				}
			}
		}
	}

	return res;
}
*/