#ifndef VEHICLEPOS_H
#define VEHICLEPOS_H

#include "LatLon.h"

struct VehiclePos
{
	LatLon coord;
	double heading;

public:
	inline JSONValue* ToJSONArray() // NOTE: pointer must be released later
	{
		JSONArray arr;
		arr.push_back(new JSONValue(this->coord.lat));
		arr.push_back(new JSONValue(this->coord.lon));
		arr.push_back(new JSONValue(this->heading));
		return new JSONValue(arr);
	}

	inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
	{
		JSONObject obj;
		obj[L"coord"] = this->coord.ToJSONObject();
		obj[L"heading"] = new JSONValue(this->heading);
		return new JSONValue(obj);
	}
};

#endif // VEHICLEPOS_H