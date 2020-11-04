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
#include "PriorKnowledgeProvider.h"

/*PriorKnowledgeProvider object*/
PriorKnowledgeProvider PriorKnowledge_Provider{};

/**
 * Complete result of OSM module request.
 *
 * @param values contain number of subrequences .
 * @return completed OSMModuleRequestResult object pointer.
 *
 * @exceptsafe This function does not throw exceptions.
 */
OSMModuleRequestResult ResultGenerator::Process(int req_num, const vector<vector<RoadInfo>>& road_info)
{
	OSMModuleRequestResult res;

	res.country = "AU";

	size_t n = 0, total_way = 0;

	for (int i = 0; i < req_num; i++)
	{
		total_way += road_info[i].size();
	}

	if (total_way == 0)
	{
		res.request_status = NOTFOUND;
	}
	else
	{
		res.request_status = SUCCESS;
	}

	vector<RoadInfo> temp(total_way);

	for (int i = 0; i < req_num; i++)
	{
		for (int j = 0; j < road_info[i].size(); j++)
		{
			temp[n] = road_info[i][j];
			n++;
		}
	}

	res.road_info = temp;

	return PriorKnowledge_Provider.Output(res);
}

/*append result*/
void ResultGenerator::Append() 
{
};

/*output with JSON format*/
OSMModuleRequestResult ResultGenerator::JsonParserOutput()
{
	return OSMModuleRequestResult();
};