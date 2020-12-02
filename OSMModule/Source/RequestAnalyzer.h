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

 /* 
  *======================================================================
  * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription
  *======================================================================
  *
  * Input: The RequestAnalyzer submodule shall be supplied with
  * 	    an array of relevant road informations objects
  * 	    the number of subrequests (TODO: this is ignored)
  * Output: The RequestAnalyzer submodule shall output an array of local road descriptions.
  *
  * System Level Requirements (SLR)
  *      1: The RequestAnalyzer shall create only one output per subrequest.
  *      2: The RequestAnalyzer shall output empty data if the array of relevant road information is empty.
  *      3: The RequestAnalyzer shall store the country of location in the output data.
  *      4: The RequestAnalyzer shall store the number of lane, their width and driving directions in the outputdata.
  *      5: The RequestAnalyzer shall store the coordinate of the center of the road in the output data.
  *      6: The RequestAnalyzer shall deduce the type of road marking for both left and right side of each lane
  *            as being either NONE, CONTINUOUS, DASHED or DOUBLE(DOUBLED)
  *
  *======================================================================
  * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription
  *======================================================================
  *
  */
class RequestAnalyzer
{
public:
	/* member function for output */
	vector<RoadPart> Process(const OSMModuleRequest& request, const vector<JSONValue*>& json_data); // SLR1, SLR2
};

#endif // REQUESTANALYZER_H