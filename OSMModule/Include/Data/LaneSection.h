#ifndef LANESECTION_H
#define LANESECTION_H

#include "Lane.h"
#include "VehiclePos.h"
#include "WayNode.h"

struct LaneSection
{
	vector<Lane> lanes;
	vector<VehiclePos> chord_coords;
	vector<WayNode> way_nodes;

public:
	inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
	{
		JSONArray lanes_arr(this->lanes.size());
		for (int i = 0; i < this->lanes.size(); i++)
			lanes_arr[i] = this->lanes[i].ToJSONObject();

		JSONArray chord_coords_arr(this->chord_coords.size());
		for (int i = 0; i < this->chord_coords.size(); i++)
			chord_coords_arr[i] = this->chord_coords[i].ToJSONArray();

		JSONArray way_nodes_arr(this->way_nodes.size());
		for (int i = 0; i < this->way_nodes.size(); i ++)
			way_nodes_arr[i] = this->way_nodes[i].ToJSONObject();

		JSONObject obj;
		obj[L"lanes"] = new JSONValue(lanes_arr);
		obj[L"chord_coords"] = new JSONValue(chord_coords_arr);
		obj[L"way_nodes"] = new JSONValue(way_nodes_arr);

		return new JSONValue(obj);
	}
};


#endif // LANESECTION_H