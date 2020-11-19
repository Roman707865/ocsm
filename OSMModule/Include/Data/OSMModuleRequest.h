#ifndef OSMMODULEREQUEST_H
#define OSMMODULEREQUEST_H

#include "VehiclePos.h"

using namespace std;

struct OSMModuleRequest
{
	vector<VehiclePos> poses;

public:
	inline JSONValue* ToJSONArray() // NOTE: pointer must be released later
	{
		JSONArray arr(this->poses.size());
		for (int i = 0; i < this->poses.size(); i++)
			arr[i] = this->poses[i].ToJSONArray();
		return new JSONValue(arr);
	}

	inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
	{
		JSONArray arr(this->poses.size());
		for (int i = 0; i < this->poses.size(); i++)
			arr[i] = this->poses[i].ToJSONObject();

		JSONObject obj;
		obj[L"poses"] = new JSONValue(arr);
		return new JSONValue(obj);
	}
};

#endif // OSMMODULEREQUEST_H