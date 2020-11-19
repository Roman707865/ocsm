#ifndef ROADPART_H
#define ROADPART_H

#include "LaneSection.h"

// https://wiki.openstreetmap.org/wiki/Highways
struct RoadPart
{
	// request position
	VehiclePos pos;

	//====================================================
	wstring name;
	wstring country;
	wstring highway;
	int width;
	int maxspeed;
	int maxheight;
	int maxwidth;
	int maxweight;
	int lane_count;
	wstring oneway;
	wstring junction;

	//====================================================
	wstring lit;
	wstring smoothness;
	wstring surface;
	wstring source;
	wstring source_maxspeed;

	//====================================================
	wstring access;
	wstring bicycle;
	wstring foot;
	wstring footway;

	//====================================================
	LatLon center_coord;
	vector<LaneSection> lane_sections;

public:
	RoadPart()
	{
		width = 0;
		maxspeed = 0;
		maxheight = 0;
		maxwidth = 0;
		maxweight = 0;
		lane_count = 0;
	}

	inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
	{
		JSONObject obj;

		obj[L"pos"] = pos.ToJSONArray();

		//====================================================
		if (!this->name.empty())
			obj[L"name"] = new JSONValue(this->name);

		if (!this->country.empty())
			obj[L"country"] = new JSONValue(this->country);

		if (!this->highway.empty())
			obj[L"highway"] = new JSONValue(this->highway);

		if (this->width != 0)
			obj[L"width"] = new JSONValue(this->width);

		if (this->maxspeed != 0)
			obj[L"maxspeed"] = new JSONValue(this->maxspeed);

		if (this->maxheight != 0)
			obj[L"maxheight"] = new JSONValue(this->maxheight);

		if (this->maxwidth != 0)
			obj[L"maxwidth"] = new JSONValue(this->maxwidth);

		if (this->maxweight != 0)
			obj[L"maxweight"] = new JSONValue(this->maxweight);

		if (this->lane_count != 0)
			obj[L"lane_count"] = new JSONValue(this->lane_count);

		if (!this->oneway.empty())
			obj[L"oneway"] = new JSONValue(this->oneway);

		if (!this->junction.empty())
			obj[L"junction"] = new JSONValue(this->junction);

		//====================================================
		if (!this->lit.empty())
			obj[L"lit"] = new JSONValue(this->lit);

		if (!this->smoothness.empty())
			obj[L"smoothness"] = new JSONValue(this->smoothness);

		if (!this->surface.empty())
			obj[L"surface"] = new JSONValue(this->surface);

		if (!this->source.empty())
			obj[L"source"] = new JSONValue(this->source);

		if (!this->source_maxspeed.empty())
			obj[L"source:maxspeed"] = new JSONValue(this->source_maxspeed);

		//====================================================
		if (!this->access.empty())
			obj[L"access"] = new JSONValue(this->access);

		if (!this->bicycle.empty())
			obj[L"bicycle"] = new JSONValue(this->bicycle);

		if (!this->foot.empty())
			obj[L"foot"] = new JSONValue(this->foot);

		if (!this->footway.empty())
			obj[L"footway"] = new JSONValue(this->footway);

		//====================================================
		obj[L"center_coord"] = this->center_coord.ToJSONArray();

		JSONArray lane_sections_arr(this->lane_sections.size());
		for (int i = 0; i < this->lane_sections.size(); i++)
			lane_sections_arr[i] = this->lane_sections[i].ToJSONObject();

		obj[L"lane_sections"] = new JSONValue(lane_sections_arr);

		return new JSONValue(obj);
	}
};

#endif // ROADPART_H