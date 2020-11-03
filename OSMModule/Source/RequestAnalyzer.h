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
#include "OSMInternal.h"
#include <stdio.h>

#define MAX_NODES_IN_WAY		2000

// node tag structure
struct nodeTag
{
	int x, y;
	string name;
};

// Json node structure
struct node 
{
	long long id;
	int x, y;
};

// road structure
struct way
{
	long long id;
	int nodeCount;

	// for all the nodes in the way
	node* nodeList[MAX_NODES_IN_WAY];
};

class RequestAnalyzer
{
private:
	/* member function to search nodes in JSON file.*/
	node* searchNode(long long nodeID);

	/* search and store way tag content in JSON file. */
	void store_ways_in_array(int id, FILE* fp);

	/* store nodes. */
	void store_nodes_in_array(FILE* fp);

	/* read white space of JSON file.*/
	bool readWhiteSpaces(FILE* fp);

	/*store different tags */
	void storeTagInArray(nodeTag* array, int* index, node curr_node);

	/* read one word in JSON file. */
	int readWord(FILE* fp, char word[50]);

	/*get tag name*/
	string returnName(FILE* fp);

	/*node structure of JSON file*/
	node* nodes, firstNode;

	/*way(road) structure */
	way* ways, * way_blgs;

	/* different tag structures*/
	nodeTag* trafficLights, * roundabouts, * eatingPlaces, * hospitals, * parkings, * busStops, * oneways, * blgNames, * streetNames, * trees;

	/* number of nodes in Json file */
	int nodeCount;

	/* number of way(road) in Json file*/
	int wayCount;

	/* number of rect*/
	int rectCount;

	/* number of each tag*/
	int blgCount;

	int trafficLightCount, roundaboutCount, eatingPlaceCount, hospitalCount, parkingCount, busStopCount, onewayCount, streetCount, treeCount;

public:

	/* 2 dimension array of road property*/
	RoadInfo** road_infor;

	/*member function for output*/
	AnalyzerResult* Output(int subreq_num);

};

#endif // REQUESTANALYZER_H