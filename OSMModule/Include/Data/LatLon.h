#ifndef LATLON_H
#define LATLON_H

#include "JSONValue.h"

struct LatLon
{
	double lat;
	double lon;

public:
	LatLon()
	{
	}

	LatLon(double lat, double lon)
	{
		this->lat = lat;
		this->lon = lon;
	}

	LatLon(JSONValue* json)
	{
		this->lat = json->AsObject().at(L"lat")->AsNumber();
		this->lon = json->AsObject().at(L"lon")->AsNumber();
	}

	inline JSONValue* ToJSONArray() // NOTE: pointer must be released later
	{
		JSONArray arr;
		arr.push_back(new JSONValue(this->lat));
		arr.push_back(new JSONValue(this->lon));
		return new JSONValue(arr);
	}

	inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
	{
		JSONObject obj;
		obj[L"lat"] = new JSONValue(this->lat);
		obj[L"lon"] = new JSONValue(this->lon);
		return new JSONValue(obj);
	}
};

#endif // LATLON_H