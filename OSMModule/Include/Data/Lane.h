#ifndef LANE_H
#define LANE_H

#include "JSONValue.h"
#include "DrivingDirection.h"
#include "RoadMarking.h"
#include "RoadMarkingColor.h"

struct Lane
{
	int id;
	int previous_id;
	int next_id;
	int maxspeed;
	double width;
	double lateral_offset;

	DrivingDirection driving_direction;
	RoadMarking left_marking;
	RoadMarking right_marking;
	RoadMarkingColor left_marking_color;
	RoadMarkingColor right_marking_color;

public:
	inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
	{
		JSONObject obj;

		obj[L"id"] = new JSONValue(this->id);
		obj[L"previous_id"] = new JSONValue(this->previous_id);
		obj[L"next_id"] = new JSONValue(this->next_id);

		if (this->maxspeed != 0)
			obj[L"maxspeed"] = new JSONValue(this->maxspeed);

		if (this->width > 0)
			obj[L"width"] = new JSONValue(this->width);

		obj[L"lateral_offset"] = new JSONValue(this->lateral_offset);

		obj[L"driving_direction"] = new JSONValue(GetDrivingDirectionString(this->driving_direction));
		obj[L"left_marking"] = new JSONValue(GetRoadMarkingString(this->left_marking));
		obj[L"right_marking"] = new JSONValue(GetRoadMarkingString(this->right_marking));
		obj[L"left_marking_color"] = new JSONValue(GetRoadMarkingColorString(this->left_marking_color));
		obj[L"right_marking_color"] = new JSONValue(GetRoadMarkingColorString(this->right_marking_color));

		return new JSONValue(obj);
	}
};

#endif // LANE_H