/*
 * This file is implemention part of OSMM module.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is interface for request to server.
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

#include "OSMModule.h"
#include "RequestLauncher.h"
#include "RequestAnalyzer.h"
#include "ResultGenerator.h"

/**
 * Send request Overpass api query to server.
 *
 * @param value contain request which have vehicle GPS points .
 * @return result of OSM module.
 *
 * @exceptsafe This function does not throw exceptions.
 */
OSMModuleRequestResult RequestDataForPath(OSMModuleRequest request)
{
	int req_num = RequestLauncher().Output(request);

    vector<vector<RoadInfo>> road_info = RequestAnalyzer().Output(req_num);

	return ResultGenerator().Process(req_num, road_info);
}








