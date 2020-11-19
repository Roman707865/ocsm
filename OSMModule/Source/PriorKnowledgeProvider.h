
/* 
 * This file is part of OSMM module and header of PriorKnowledgeProvider submodule.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is submodule for provide lanes of road detail property.
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

#ifndef PRIORKNOWLEDGEPROVIDER_H
#define PRIORKNOWLEDGEPROVIDER_H

#include "OSMModule.h"

 /* 
  *======================================================================
  * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription
  *======================================================================
  *
  * Input: The PriorKnowledgeProvider submodule shall be supplied with:
  *      a country name
  *      a type of road corresponding to the OSM tag
  *           (see Highway Key of OpenStreetMap. May 2020. URL:https://wiki.openstreetmap.org/wiki/Key:highway,
				 Key_highway - OpenStreetMap Wiki.mhtml).
  *
  * Output: The PriorKnowledgeProvider submodule shall return
  *      the number of lanes for the given type of road
  *      the width of each lane
  *
  * System Level Requirements (SLR)
  *      1: the PriorKnowledgeProvider shall return one output per input request
  *      2: the PriorKnowledgeProvider shall return the number of lane, type and color of roadmarking on eachside,
			 and width of each lane for every pair of country and OSM road type
  *
  *======================================================================
  * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription
  *======================================================================
  */
class PriorKnowledgeProvider
{
public:
    int GetWayWidth(const wstring& country, const wstring& highway);
    int GetMaxSpeed(const wstring& country, const wstring& highway);
	int GetLaneCount(const wstring& country, const wstring& highway);
    int GetLaneWidth(const wstring& country, const wstring& highway);

	RoadMarking GetLeftMarking(const wstring& country, const wstring& highway);
	RoadMarking GetRightMarking(const wstring& country, const wstring& highway);
	RoadMarkingColor GetLeftMarkingColor(const wstring& country, const wstring& highway);
	RoadMarkingColor GetRightMarkingColor(const wstring& country, const wstring& highway);
};

#endif // PRIORKNOWLEDGEPROVIDER_H