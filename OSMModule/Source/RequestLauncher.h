/*
 * This file is part of OSMM module and header of RequestLauncher submodule.
 * Developed for the OpenStreet Data Management System.
 * The RequestLauncher submodule shall be supplied with a OSMModuleRequest.
 * The RequestLauncher submodule shall output an array of JSON objects.
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

#ifndef REQUESTLAUNCHER_H
#define REQUESTLAUNCHER_H

#include "OSMModule.h"

#include <string>

using namespace std;

class RequestLauncher
{
private:

	/*seach range of GPS point */
	double around;

	/*member function for prepare submit to server*/
	void Begin(OSMModuleRequest request);

	/*member function to make Overpass api query*/
	string Create_Query(LatLon pos);

	/*member function for connect to server and get JSON result */
	int Get_Json(int id, string query, string fname);
	int Get_CountryName(int id, LatLon pos);

public:
	/*number of subrequest*/
	int subrequest_cnt;
	vector<int> res;

	/*result output of RequestLauncher submodule*/
	int Output(OSMModuleRequest request);
};

#endif // REQUESTLAUNCHER_H