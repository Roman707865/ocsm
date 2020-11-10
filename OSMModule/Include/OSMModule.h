/*
 * This file is header part of OSMM module.
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

#ifndef OSMMODULE_H
#define OSMMODULE_H

#include <string>
#include <vector>

using namespace std;

struct LatLon
{
	double longitude;
	double latitude;
};

struct VehiclePos
{
	LatLon latlon;
	double heading;
};

struct OSMModuleRequest
{
	vector<VehiclePos> poses_buf;
};

enum RequestStatus
{
	SUCCESS,
	FAILED,
	NOTFOUND
};



struct Lane
{
	long long id;
	long long next_id;
	long long previous_id;
	int speedlimit;
	double width;
	double lateraloffset;
	int driving_direction;
	int left_marking;
	int right_marking;
	int left_marking_color;
	int right_marking_color;

};

struct LaneSection
{
	vector<Lane> lanes_buf;
	vector<LatLon> chord_coordinates_buf;
};

struct RoadPart
{
	vector<LaneSection> lanesection_buf;
	
};

struct RoadInfo
{
	string country;
	wstring highway;
	wstring lanes;
	wstring lit;
	wstring maxspeed;
	wstring name;
	wstring smoothness;
	wstring surface;
	wstring width;
	LatLon center_pos;
};


struct OSMModuleRequestResult
{
	RequestStatus request_status;
	vector<RoadPart> roadpart_buf;
	vector<RoadInfo> road_info;
	string country;
};

 /* main method to communicate with the module */
OSMModuleRequestResult RequestDataForPath(OSMModuleRequest request);


#endif // OSMMODULE_H
