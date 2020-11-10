/*
 * This file is part of OSMM module and implemention of PriorKnowledgeProvider submodule.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is submodule for provide lanes of road detail property.
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
#include "PriorKnowledgeProvider.h"

const int  Get_data_by_country(string cn, int kind);
 /**
 * Search lane properties and add it on OSMModuleRequestResult.
 *
 * @param value contain OSMModuleRequestResult object pointer.
 * @return OSMModuleRequestResult object pointer .
 *
 * @exceptsafe This function does not throw exceptions.
 */
OSMModuleRequestResult& PriorKnowledgeProvider::Output(OSMModuleRequestResult& res)
{


	int k_id = 0;

    vector<RoadPart> roadpart(res.road_info.size());

	for (int j = 0; j < res.road_info.size(); j++)
	{
        roadpart[j].lanesection_buf.resize(1);
		
		int n;
		
		string cn = res.road_info[j].country;

		/****************************************setting lane properties***************************************************************/
		if (res.road_info[j].lanes.empty())
		{
			
			n = Get_data_by_country(cn,  0);

			res.road_info[j].lanes = to_wstring(n);
	
		}
		else
		{
			n = _wtoi(res.road_info[j].lanes.c_str());
		}
	     

	    roadpart[j].lanesection_buf[0].lanes_buf.resize(n);

		for (size_t i = 0; i < n; i++)
		{
			if (i == 0 && j==0)
			{
				roadpart[j].lanesection_buf[0].lanes_buf[i].id = 0;

			}
			else
			{
				k_id++;
				roadpart[j].lanesection_buf[0].lanes_buf[i].id = k_id;
			}
			
			
			roadpart[j].lanesection_buf[0].lanes_buf[i].driving_direction = Get_data_by_country(cn, 8);
			roadpart[j].lanesection_buf[0].lanes_buf[i].lateraloffset = Get_data_by_country(cn, 2);
			roadpart[j].lanesection_buf[0].lanes_buf[i].speedlimit = Get_data_by_country(cn, 1);
			roadpart[j].lanesection_buf[0].lanes_buf[i].left_marking = Get_data_by_country(cn, 3);
			roadpart[j].lanesection_buf[0].lanes_buf[i].right_marking = Get_data_by_country(cn, 4);
			roadpart[j].lanesection_buf[0].lanes_buf[i].left_marking_color = Get_data_by_country(cn, 5);
			roadpart[j].lanesection_buf[0].lanes_buf[i].right_marking_color = Get_data_by_country(cn, 6);
			roadpart[j].lanesection_buf[0].lanes_buf[i].width = Get_data_by_country(cn, 7);

		}

	
		
	}

	/****************************************setting prev_id& next id of lanes******************************************************/
	for (int j = 0; j < res.road_info.size(); j++)
	{
		if (j > 0 && j < res.road_info.size() - 1)
		{

			for (size_t k = 0; k < roadpart[j].lanesection_buf[0].lanes_buf.size(); k++)
			{
				for (size_t m = 0; m < roadpart[j - 1].lanesection_buf[0].lanes_buf.size(); m++)
				{
					if (roadpart[j].lanesection_buf[0].lanes_buf[k].driving_direction ==
						roadpart[j - 1].lanesection_buf[0].lanes_buf[m].driving_direction)
					{
						roadpart[j].lanesection_buf[0].lanes_buf[m].previous_id = roadpart[j - 1].lanesection_buf[0].lanes_buf[m].id;
					}

				}

			}


			for (size_t k = 0; k < roadpart[j].lanesection_buf[0].lanes_buf.size(); k++)
			{
				for (size_t m = 0; m < roadpart[j + 1].lanesection_buf[0].lanes_buf.size(); m++)
				{
					if (roadpart[j].lanesection_buf[0].lanes_buf[k].driving_direction ==
						roadpart[j + 1].lanesection_buf[0].lanes_buf[m].driving_direction)
					{
						roadpart[j].lanesection_buf[0].lanes_buf[m].next_id = roadpart[j + 1].lanesection_buf[0].lanes_buf[m].id;
					}

				}

			}

		}
	}
	res.roadpart_buf = roadpart;
	return res;
}
/**
* Search lane standard properties by countries .
*
* @param value contain country name and search item.
* @return property value defined in OSM.(Refrence https://wiki.openstreetmap.org/wiki/Key:highway)
*
* @exceptsafe This function does not throw exceptions.
*/
const int  Get_data_by_country(string cn, int kind)
{
	Lane temp;

	int n;
	if (cn == "Australia")
	{
		
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	
		
	}
	else if (cn == "Austria")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Belarus")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Belgium")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Brazil")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Croatia")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Czechia")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Denmark")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Dominican Republic")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "France")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Georgia")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Germany")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Greece")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Hungary")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
	}
	else if (cn == "Indonesia")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Iran")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Israel")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Italy")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Japan")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Korea")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Malaysia")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Netherlands")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "New Zealand")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Norway")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Philippines")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Poland")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Portugal")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Romania")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Russia")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Spain")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Sweden")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Switzerland")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "Turkey")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "United Kingdom")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else if (cn == "United States")
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}
	else
	{
		n = 2;
		temp.speedlimit = 100;
		temp.lateraloffset = 0;
		temp.left_marking = 0;
		temp.right_marking = 0;
		temp.left_marking_color = 3;
		temp.right_marking_color = 3;
		temp.width = 20;
		temp.driving_direction = 1;
	}

	switch (kind)
	{
		case 0:
			return n;
		case 1:
			return temp.speedlimit;
		case 2:
			return (int)temp.lateraloffset;
		case 3:
			return temp.left_marking;
		case 4:
			return temp.right_marking;
		case 5:
			return temp.left_marking_color;
		case 6:
			return temp.right_marking_color;
		case 7:
			return (int)temp.width;
		case 8:
			return temp.driving_direction;
	}

	return 0;
}