/*
 * This file is part of OSMM module and implemention of RequestAnalyzer submodule.
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

#ifndef REQUESTANALYZER_H
#define REQUESTANALYZER_H

#include "OSMModule.h"
#include <stdio.h>
#include <vector>
#include "JSON.h"

#define MAX_NODES				100000
#define MAX_WAYS				1000
#define MAX_NODES_IN_WAY		2000

#define MAX_BUILDINGS			2000
#define MAX_NODE_TAGS			2000

struct Analyzer_In
{
	vector<string> country;
	vector<JSONValue*> JsonArray;
};

class RequestAnalyzer
{
private:
	
public:
	/*member function for output*/
	vector<vector<RoadInfo>> Output(Analyzer_In res);
};

#endif // REQUESTANALYZER_H