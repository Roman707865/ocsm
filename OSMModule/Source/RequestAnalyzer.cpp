
/*
 * This file is part of OSMM module and header of RequestAnalyzer submodule.
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

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "RequestAnalyzer.h"
#include <sstream>
#include <iostream>
#include <string.h>

 /**
 * Output Analyze Result of JSON file.
 *
 * @param values Container number of subrequences.
 * @return array of road description
 *
 * @exceptsafe This function does not throw exceptions.
 */
vector<vector<RoadInfo>> RequestAnalyzer::Output(int subreq_num)
{
	vector<vector<RoadInfo>> road_info;
	vector<node> nodes(MAX_NODES);

	road_info.resize(subreq_num);

	for (int i = 0; i < subreq_num; i++)
	{
		// anyalyze of result
		string json_name = "database";
		string num = to_string(i + 1);
		json_name.append(num);
		json_name.append(".json");

		FILE* fp = fopen(json_name.c_str(), "r+");

		nodeCount = 0;
		store_nodes_in_array(nodes, fp);

		if (nodeCount > 0)
			store_ways_in_array(road_info, nodes, i, fp);


#ifdef _WIN32
		_fcloseall();
#else
		fcloseall();
#endif
	}

	return road_info;
}

/**
 * Store the ways from nodes array in JSON file.
 *
 * @param values mean index of subrequence and file pointer.
 * @return no value .
 *
 * @exceptsafe This function does not throw exceptions.
 */
void RequestAnalyzer::store_ways_in_array(vector<vector<RoadInfo>>& road_info, vector<node>& nodes, int id, FILE* fp)
{
	int wayIndex = 0;
	int buildingIndex = 0;
	char word[1000], ch = 'a';

	vector<way> ways(MAX_WAYS);
	road_info[id].resize(MAX_WAYS);

	/* the fp continues from where store_nodes_in_array left off*/
	while (!feof(fp))
	{
		readWord(fp, word);

		if (!strcmp(word, "0"))
			break;

		/* encountered "way" */
		if (!strcmp(word, "\"way\","))
		{
			/* read "id:" */
			readWord(fp, word);

			/* read id value*/
			readWord(fp, word);

			/* converting string to long long*/
			stringstream sstr(word);
			long long val;
			sstr >> val;

			ways[wayIndex].id = val;

			/* read "nodes":*/
			readWord(fp, word);

			/* read '[' */
			readWord(fp, word);

			ways[wayIndex].nodeCount = 0;

			/* loop reading off and storing the nodes in a way */
			ch = '[';
			while (ch != ']' && !feof(fp))
			{
				readWord(fp, word);
				stringstream sstr(word);
				long long val;
				sstr >> val;

				ways[wayIndex].nodeList[ways[wayIndex].nodeCount] = searchNode(nodes, val);

				ways[wayIndex].nodeCount++;

				readWhiteSpaces(fp);
				fscanf(fp, "%c", &ch);
				/* check if its the ] following the last node value*/
				if (ch != ']')
					fseek(fp, -1, SEEK_CUR);
			}
			/* read ,*/
			fscanf(fp, "%c", &ch);
			readWord(fp, word);

			if (!strcmp(word, "\"tags\":"))
			{
				// 	cout<< "********* road" << wayIndex << " details*********" << endl;
					// read the tags till you encounter some street element
				readWord(fp, word);
				while (strcmp(word, "},"))
				{

					readWord(fp, word);

					/*cout << word <<" " ;

					if (!strcmp(word, "}") || !strcmp(word, "0"))
						break;

					readWord(fp, word);

					cout << word << endl;*/

					if (!strcmp(word, "}") || !strcmp(word, "0"))
						break;

					if (!strcmp(word, "\"highway\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].highway = word;
					}
					if (!strcmp(word, "\"lanes\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].lanes = word;
					}

					if (!strcmp(word, "\"lit\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].lit = word;
					}
					if (!strcmp(word, "\"maxspeed\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].maxspeed = word;
					}
					if (!strcmp(word, "\"name\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].name = word;
					}
					if (!strcmp(word, "\"smoothness\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].smoothness = word;
					}
					if (!strcmp(word, "\"surface\":"))
					{
						readWord(fp, word);
						road_info[id][wayIndex].surface = word;
					}

				}
			}

			/* one more way gone into ways array*/
			wayIndex++;
			
			if (wayIndex == MAX_WAYS)
			{
				cout << "\nway count greater than max way limit, try somewhere less congested";
				wayCount = wayIndex;
				blgCount = buildingIndex;
				cout << "\n\nNo of ways in this data : " << wayCount << endl;
				return;
			}
		}
	}

	wayCount = wayIndex;
	blgCount = buildingIndex;

	road_info[id].resize(wayCount);
	// cout << "\n\nNo of ways in this data : " << wayCount<<endl;
}

/**
 * Store the nodes from file fp .
 *
 * @param value contain file pointer.
 * @return no value .
 *
 * @exceptsafe This function does not throw exceptions.
 */
void RequestAnalyzer::store_nodes_in_array(vector<node>& nodes, FILE* fp)
{
	char word[1000];
	double lat, lon;
	int treeRand;
	
	vector<nodeTag> trafficLights(MAX_NODE_TAGS);
	vector<nodeTag> roundabouts(MAX_NODE_TAGS);
	vector<nodeTag> eatingPlaces(MAX_NODE_TAGS);
	vector<nodeTag> hospitals(MAX_NODE_TAGS);
	vector<nodeTag> parkings(MAX_NODE_TAGS);
	vector<nodeTag> busStops(MAX_NODE_TAGS);
	vector<nodeTag> trees(MAX_NODE_TAGS);

	fseek(fp, 0, SEEK_SET);

	while (!feof(fp))
	{
		int res = readWord(fp, word);
		if (res < 0) return;
		// break off if its last chunk size 0
		if (!strcmp(word, "0"))
			break;

		// break off if word is way
		if (!strcmp(word, "\"way\","))
		{
			fseek(fp, -10, SEEK_CUR);
			break;
		}

		if (!strcmp(word, "\"node\","))
		{
			// a random no. to see if I draw a tree
			treeRand = rand() % 1000;

			// read "id":
			readWord(fp, word);

			// read the acutal node id value
			readWord(fp, word);

			// converting string to long long
			stringstream sstr(word);
			long long val;
			sstr >> val;

			nodes[nodeCount].id = val;

			// read "lat:"
			readWord(fp, word);

			// read latitude value
			readWord(fp, word);

			lat = atof(word);

			// read "lon:"
			readWord(fp, word);

			// read longitude value
			readWord(fp, word);
			lon = atof(word);

			// now take care of the tags in a node
			readWord(fp, word);

			// 50/1000 probability of a tree.
			if (treeRand < 50 && treeCount < MAX_NODE_TAGS)
			{
				storeTagInArray(trees, &treeCount, nodes[nodeCount]);
			}

			if (!strcmp(word, "\"tags\":"))
			{
				// read the tags till you encounter some street element
				while (strcmp(word, "},"))
				{
					readWord(fp, word);

					if (!strcmp(word, "\"traffic_signals\",") || !strcmp(word, "\"traffic_signals\""))
					{
						storeTagInArray(trafficLights, &trafficLightCount, nodes[nodeCount]);
						if (trafficLightCount > MAX_NODE_TAGS)
						{
							cout << "too much tl ";
							exit(0);
						}
					}

					if (!strcmp(word, "\"mini_roundabout\",") || !strcmp(word, "\"mini_roundabout\""))
					{
						// cout << "\nA roundabout";
						storeTagInArray(roundabouts, &roundaboutCount, nodes[nodeCount]);
					}

					if (!strcmp(word, "\"restaurant\",") || !strcmp(word, "\"restaurant\"") || !strcmp(word, "\"brand\":"))
					{
						string hotelName;
						storeTagInArray(eatingPlaces, &eatingPlaceCount, nodes[nodeCount]);
						hotelName = returnName(fp);
						eatingPlaces[eatingPlaceCount - 1].name = hotelName;

						if (eatingPlaceCount > MAX_NODE_TAGS)
						{
							cout << "too much food ";
							exit(0);
						}
						// cout << "\nA yume";
					}

					if (!strcmp(word, "\"hospital\",") || !strcmp(word, "\"hospital\""))
					{
						string hospName;
						// cout << "\nA medico";
						storeTagInArray(hospitals, &hospitalCount, nodes[nodeCount]);
						hospName = returnName(fp);
						hospitals[hospitalCount - 1].name = hospName;

						if (hospitalCount > MAX_NODE_TAGS)
						{
							cout << "too much sickeness ";
							exit(0);
						}
					}

					if (!strcmp(word, "\"parking\",") || !strcmp(word, "\"parking\""))
					{
						// cout << "\nA park";
						storeTagInArray(parkings, &parkingCount, nodes[nodeCount]);

						if (parkingCount > MAX_NODE_TAGS)
						{
							cout << "too much park ";
							exit(0);
						}
					}
				}

				if (!strcmp(word, "\"bus_stop\",") || !strcmp(word, "\"bus_stop\"") || !strcmp(word, "\"bus_station\",") || !strcmp(word, "\"bus_station\""))
				{
					// cout << "\nbus";
					storeTagInArray(busStops, &busStopCount, nodes[nodeCount]);
					if (busStopCount > MAX_NODE_TAGS)
					{
						cout << "too much bus ";
						exit(0);
					}
				}
			}

			nodeCount++;
		}
	}
	// cout << "\nno of nodes in llist" << nodeCount << "tree" << treeCount;

}
/**
 * Search node in node array .
 *
 * @param value contain nodeID.
 * @return node structure pointer.
 *
 * @exceptsafe This function does not throw exceptions.
 */
node* RequestAnalyzer::searchNode(vector<node>& nodes, long long nodeID)
{
	for (int i = 0; i < nodeCount; i++)
	{
		if (nodeID == nodes[i].id)
		{
			return &nodes[i];
		}
	}

	cout << "\nSystem ERROR !! not found : " << nodeID;
	exit(0);
	return 0;
}

/**
 * Read white spaces(empty part) of JSON file .
 *
 * @param value contain file pointer.
 * @return true or false about result.
 *
 * @exceptsafe This function does not throw exceptions.
 */
bool RequestAnalyzer::readWhiteSpaces(FILE* fp)
{
	if (feof(fp))
		return false;

	char ch;
	bool word_break = true;

	/* eat ch if its newline*/
	while (true)
	{
		fscanf(fp, "%c", &ch);

		if (ch == '\n')
		{
			word_break = false;
		}
		else
		{
			/* go one back as loop will have to break as character not \n*/
			fseek(fp, -1, SEEK_CUR);
			break;
		}
	}

	/* eat ch if its space*/
	while (true)
	{
		fscanf(fp, "%c", &ch);
		if (ch == ' ')
		{
			word_break = false;
		}
		else
		{
			/* go one back as loop will have to break as character not \n'*/
			fseek(fp, -1, SEEK_CUR);
			break;
		}
	}
	return word_break;
}

/**
 * Store tag in array .
 *
 * @param value contain nodeTag pointer, index of nodetag and current node.
 * @return none.
 *
 * @exceptsafe This function does not throw exceptions.
 */
void RequestAnalyzer::storeTagInArray(vector<nodeTag>& array, int* index, node curr_node)
{
	array[*index].name = "empty";
	array[*index].x = curr_node.x;
	array[*index].y = curr_node.y;

	*index = *index + 1;
}

/**
 * Read one word in JSON file .
 *
 * @param value contain file pointer and string pointer to store word.
 * @return integer result.If it is more than 0, success.else filed.
 *
 * @exceptsafe This function does not throw exceptions.
 */
int RequestAnalyzer::readWord(FILE* fp, char word[50])
{
	char ch;
	char chunkSize[50], wordEnd[50];
	bool word_break = false;

	fscanf(fp, "%s", word);

	/* eat whitespaces */
	word_break = readWhiteSpaces(fp);

	/* read the next char*/
	int res = fscanf(fp, "%c", &ch);

	if (ch == '\r')
	{
		fscanf(fp, "%s", chunkSize);
		// cout << "\nchunk size : " << chunkSize;

		/* read off \r and \n following the chunk size*/
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%c", &ch);

		if (!strcmp(chunkSize, "0"))
		{
			cout << "\nend of input";
			strcpy(word, chunkSize);
			return 1;
		}

		/* as if word break is false then it is seen that word is not broken by chunk size*/
		if (word_break == true)
			word_break = readWhiteSpaces(fp);

		if (word_break)
		{
			fscanf(fp, "%s", wordEnd);
			strcat(word, wordEnd);
			// cout << "\nFull word: " << word;
		}
	}
	else
		fseek(fp, -1, SEEK_CUR);
	return res;
}

/**
 * Read amenity'name' tag in JSON file .
 *
 * @param value contain file pointer.
 * @return amenity name .
 *
 * @exceptsafe This function does not throw exceptions.
 */
string RequestAnalyzer::returnName(FILE* fp)
{
	char word[1000] = "", amenityName[1000] = "empty";
	while (strcmp(word, "\"name\":"))
	{
		readWord(fp, word);
		if (!strcmp(word, "}"))
		{
			return amenityName;
		}
	}

	/* the name of the amenity*/
	char ch = 'a';
	int i = 0;

	/*read " at begining of name*/
	fscanf(fp, "%c", &ch);
	while (ch != '\n')
	{
		fscanf(fp, "%c", &ch);
		amenityName[i] = ch;
		i++;
	}

	/*so that ending " is not stored*/
	if (amenityName[i - 2] == ',')
		amenityName[i - 3] = 0;
	else
		amenityName[i - 2] = 0;

	// cout << "\n" << amenityName;
	return amenityName;
}
