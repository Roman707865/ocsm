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
	VehiclePos* poses_buf;
	size_t poses_buf_sz;
};

enum RequestStatus
{
	SUCCESS,
	FAILED,
	NOTFOUND
};

enum DrivingDirection
{
	POSITIVE,
	NEGATIVE,
	BOTH
};

enum RoadMarking
{
	NONE,
	CONTINUOUS,
	DASHED,
	_DOUBLE
};

enum RoadMarkingColor
{
	WHITE,
	YELLOW,
	RED,
	GREEN,
	BLUE
};

struct Lane
{
	long long id;
	long long next_id;
	long long previous_id;
	int speedlimit;
	double width;
	double lateraloffset;
	DrivingDirection driving_direction;
	RoadMarking left_marking;
	RoadMarking right_marking;
	RoadMarkingColor left_marking_color;
	RoadMarkingColor right_marking_color;
};

struct LaneSection
{
	Lane* lanes_buf;
	size_t lane_buf_sz;
	LatLon* chord_coordinates_buf;
	size_t chord_coordinates_buffer_buf_sz;
};

struct RoadPart
{
	LaneSection* lanesection_buf;
	size_t lanesection_buf_sz;
};

struct RoadInfo
{
	string highway;
	string lanes;
	string lit;
	string maxspeed;
	string name;
	string smoothness;
	string surface;
};

struct OSMModuleRequestResult
{
	RequestStatus request_status;
	RoadPart* roadpart_buf;
	RoadInfo* Road_infor;
	size_t roadpart_buf_sz;
	string country;
};

 /* main method to communicate with the module */
OSMModuleRequestResult* RequestDataForPath(OSMModuleRequest request);

#endif // OSMMODULE_H
