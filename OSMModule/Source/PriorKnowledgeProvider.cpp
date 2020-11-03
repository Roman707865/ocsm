/*
 * This file is part of OSMM module and implemention of PriorKnowledgeProvider submodule.
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
#include "PriorKnowledgeProvider.h"

 /**
 * Search lane properties and add it on OSMModuleRequestResult.
 *
 * @param value contain OSMModuleRequestResult object pointer.
 * @return OSMModuleRequestResult object pointer .
 *
 * @exceptsafe This function does not throw exceptions.
 */

OSMModuleRequestResult* PriorKnowledgeProvider::Output(OSMModuleRequestResult* res)
{
	constexpr int kNumberOfLanes = 3;
	Lane negativelane{ 0, -1, -1, 50, 3.75F, 0.0F, DrivingDirection::NEGATIVE };
	Lane positivelaneone{ 0, -1, -1, 50, 3.75F, 0.0F, DrivingDirection::NEGATIVE };
	Lane positivelanetwo{ 0, -1, -1, 50, 4.0F, 3.75F, DrivingDirection::NEGATIVE };
	positivelaneone.left_marking = RoadMarking::CONTINUOUS;
	positivelaneone.right_marking = RoadMarking::DASHED;
	negativelane.id = 0;
	positivelaneone.id = 1;
	positivelanetwo.id = 2;

	RoadPart* roadpart = new RoadPart[res->roadpart_buf_sz];

	for (int j = 0; j < res->roadpart_buf_sz; j++)
	{
		roadpart[j].lanesection_buf_sz = 1;
		roadpart[j].lanesection_buf = (LaneSection*)malloc(
			roadpart->lanesection_buf_sz * sizeof(LaneSection));
		roadpart[j].lanesection_buf[0].lane_buf_sz = kNumberOfLanes;
		roadpart[j].lanesection_buf[0].lanes_buf =
			(Lane*)malloc(kNumberOfLanes * sizeof(Lane));
		roadpart[j].lanesection_buf[0].lanes_buf[0] = negativelane;
		roadpart[j].lanesection_buf[0].lanes_buf[1] = positivelaneone;
		roadpart[j].lanesection_buf[0].lanes_buf[2] = positivelanetwo;
	}

	res->roadpart_buf = roadpart;
	return res;
}