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
#include "JSON.h"
using namespace std;

struct Launcher_Out
{
	vector<string> country;
	vector<JSONValue*> JsonArray;
};

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
	int Get_Json(int id, string query);
	
	int Get_CountryName(int id, LatLon pos);

	vector<char>  Get_JSON_Body(vector<char> buf, int id);

	vector<JSONValue*> res;
	
	vector<string> country;

	
public:
	
	/*result output of RequestLauncher submodule*/
	Launcher_Out  Output(OSMModuleRequest request);
};

#endif // REQUESTLAUNCHER_H