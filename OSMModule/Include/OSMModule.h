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
 *
 *
 *======================================================================
 * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription
 *======================================================================
 *
 * The main method to communicate with the module is:
 *		OSMModuleRequestResult *RequestDataForPath (OSMModuleRequest request ) ;
 *		This method performs a synchronous request and return a pointer to the output request structure.
 *
 * Functional System Level Requirements (SLR)
 *		1: When being provided with a OSMModuleRequest, the OSMM shall return a OSMModuleRequestResult.
 *		2: The OSMM shall give result for GPS traces located in any country of the world.
 *		3: If a GPS trace does not perfectly matches a road trace recorded in the OSM database,
 *			the requestresult shall contain information about the closest plausible road trace.
 *		4: If no plausible road trace exist nearby the supplied GPS trace, the OSMM shall tag the result as NOTFOUND.
 *		5: If a connection problem with the OSM servers occur, or if the result from the OSM server is corrupted,
 *			the OSMM shall tag the result as FAILED.
 *		6: The module shall be able to process requests with up to 72 geocoordinates.
 *		7: The module shall be able to process requests with a single geocoordinate.
 *
 * General Architecture
 *		The OSMModuleRequest is processed by the RequestLauncher.
 *		This module will process n singlesubrequests with the OverpassAPI.
 *		Each of the single subrequest result from the OverpassAPI will beprocessed by a JsonParser module
 *			that will extract relevant information.
 *		Each of these extractions willbe passed to a RequestAnalyzer that will build a consistent local road description.
 *		The RequestAnalyzer will use the PriorKnowledgeProvider, to enrich and or fill gaps in the data.
 *		Each of the local roaddescriptions will be supplied to the ResultGenerator,
 *			that will build a consistent result along thegeodetic path supplied in the request.
 *
 *======================================================================
 * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription
 *======================================================================
 *
 */

#ifndef OSMMODULE_H
#define OSMMODULE_H

#include "OSMModuleRequest.h"
#include "OSMModuleRequestResult.h"

#define MAX_POINTS_COUNT	72

/* main method to communicate with the module */
OSMModuleRequestResult RequestDataForPath(OSMModuleRequest request);

#endif // OSMMODULE_H
