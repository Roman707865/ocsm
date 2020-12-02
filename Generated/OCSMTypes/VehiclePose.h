#ifndef VEHICLEPOSE_H
#define VEHICLEPOSE_H

#include <vector>
#include <string>

namespace OCSMTypes {

	class VehiclePose
	{
		double x;
		double y;
		double roll;
		double pitch;
		double yaw;
		std::wstring time;
	public:
		// Public attributes
		//  
		inline JSONValue* ToJSONArray() // NOTE: pointer must be released later
		{
			JSONArray arr;
			arr.push_back(new JSONValue(this->x));
			arr.push_back(new JSONValue(this->y));
			arr.push_back(new JSONValue(this->roll));
			arr.push_back(new JSONValue(this->pitch));
			arr.push_back(new JSONValue(this->yaw));
			arr.push_back(new JSONValue(this->time));
			return new JSONValue(arr);
		}

		inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
		{
			JSONObject obj;
			obj[L"x"] = new JSONValue(this->x);
			obj[L"y"] = new JSONValue(this->y);
			obj[L"yaw"] = new JSONValue(this->yaw);
			obj[L"pitch"] = new JSONValue(this->pitch);
			obj[L"roll"] = new JSONValue(this->roll);
			obj[L"time"] = new JSONValue(this->time);
			return new JSONValue(obj);
		}
	};
} // end of package namespace

#endif // VEHICLEPOSE_H
