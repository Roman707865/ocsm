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

#ifndef RESULTGENERATOR_H
#define RESULTGENERATOR_H

#include "OSMModule.h"

class ResultGenerator
{
public:
	/* main process member function of this module*/
	OSMModuleRequestResult Process(size_t req_num, const vector<vector<RoadInfo>>& road_info);

	/*append result*/
	void Append();

	/*output with JSON format*/
	OSMModuleRequestResult JsonParserOutput();

};

#endif // RESULTGENERATOR_H