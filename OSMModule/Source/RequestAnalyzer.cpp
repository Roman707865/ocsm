
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
#include <sstream>
#include <iostream>
#include <string.h>
#include <math.h>

 /**
 * Output Analyze Result of JSON file.
 *
 * @param values contain JSON object array.
 * @return array of road description
 *
 * @exceptsafe This function does not throw exceptions.
 */
vector<vector<RoadInfo>> RequestAnalyzer::Output(Analyzer_In res)
{
	vector<vector<RoadInfo>> road_info;

	LatLon min_pos;

	size_t subreq_num = res.JsonArray.size();

	size_t way_cnt = 0;

	road_info.resize(subreq_num);


	for (int i = 0; i < subreq_num; i++)
	{
		double min_d = 1000.0;

		if (res.JsonArray[i]->IsObject() == true)
		{

			JSONObject root;

			JSONArray elements = res.JsonArray[i]->Child(L"elements")->AsArray();

			for (size_t j = 0; j < elements.size(); j++)
			{
				root = elements[j]->AsObject();

				if (root.find(L"type") != root.end() && root[L"type"]->IsString())
				{
					wstring key = root[L"type"]->AsString().c_str();
					
					if (key == L"node")
					{
						double x = root[L"lat"]->AsNumber();
						double y = root[L"lon"]->AsNumber();

						double dx = res.pos.latitude - x;
						double dy = res.pos.longitude - y;
						double d = sqrt(dx * dx + dy * dy);

						if (d < min_d)
						{
							min_d = d;
							
							min_pos.latitude = x;

							min_pos.longitude = y;
						}
 					}

					if (key == L"way")
					{
						RoadInfo temp;

						JSONObject tags = root[L"tags"]->AsObject();
						if (tags[L"highway"] != NULL)
							temp.highway = tags[L"highway"]->AsString().c_str();
						
						if (tags[L"lanes"] != NULL)
							temp.lanes = tags[L"lanes"]->AsString().c_str();
						
						if (tags[L"maxspeed"] != NULL)
							temp.maxspeed = tags[L"maxspeed"]->AsString().c_str();
						
						if (tags[L"smoothness"]!=NULL)
							temp.smoothness = tags[L"smoothness"]->AsString().c_str();
						
						if (tags[L"surface"] != NULL)
							temp.surface = tags[L"surface"]->AsString().c_str();
						
						if (tags[L"width"] != NULL)
							temp.width = tags[L"width"]->AsString().c_str();
						
						if (tags[L"lit"] != NULL)
							temp.lit = tags[L"lit"]->AsString().c_str();
						
						if (tags[L"name"] != NULL)
							temp.name = tags[L"name"]->AsString().c_str();
						
						temp.country = res.country[i];
						
						temp.center_pos = min_pos;

						road_info[i].push_back(temp);
						way_cnt++;
					}

				}
			}

		}
	}

	return road_info;
}
