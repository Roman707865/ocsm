#ifndef OVERPASSAPI_H
#define OVERPASSAPI_H

#include "OSMModule.h"
#include <iostream>
#include "HttpRequest.hpp"

using namespace std;

class OverpassAPI
{
public:
	static inline string GetResponse(string query)
	{
		http::Request request("www.overpass-api.de/api/interpreter");

		const http::Response response = request.send("POST", query, {
			"Content-Type: application/json"
			});

		return std::string(response.body.begin(), response.body.end());
	}

	static inline JSONValue* GetWayData(LatLon coord) // NOTE: pointer must be released later
	{
		
		string query = "[out:json];way(around:15," + to_string(coord.lat) + "," + to_string(coord.lon) + ")[highway~\"" + "." + "\"][highway!~\"" + "path|track|cycleway|footway\"""];out tags geom;";
		
		string data = GetResponse(query);

		//cout << data;

		JSONValue* json_value = JSON::Parse(data.c_str());
		if (json_value == 0)
			return 0;

		JSONValue* result = JSON::Parse(json_value->Child(L"elements")->Stringify().c_str()); // NOTE: pointer must be released later

		delete json_value;
		
		return result;
	}

	#define NODE_AROUND_WAY_TAG_COUNT	15

	static inline JSONValue* GetNodesData(const vector<VehiclePos>& coords) // NOTE: pointer must be released later
	{
		string tags[NODE_AROUND_WAY_TAG_COUNT] =
		{
			"highway",
			"barrier",
			"traffic_calming",
			"restriction",
			"bus",
			"railway",
			"motorway",
			"bicycle",
			"foot",
			"footway",
			"parking",
			"crossing",
			"amenity=bus_station",
			"route",
			"public_transport"
		};

		string filter = "(around:15";
		for (int i = 0; i < coords.size(); i++)
			filter += "," + to_string(coords[i].coord.lat) + "," + to_string(coords[i].coord.lon);
		filter += ");";

		string query = "[out:json];(";
		for (int i = 0; i < NODE_AROUND_WAY_TAG_COUNT; i++)
			query += "node[" + tags[i] + "]" + filter;
		query += ");out tags geom;";

		//cout << endl << query << endl;

		try
		{
			string data = GetResponse(query);

			//cout << data;

			JSONValue* json_value = JSON::Parse(data.c_str());

			if (json_value == 0)
				return 0;

			JSONValue* result = JSON::Parse(json_value->Child(L"elements")->Stringify().c_str()); // NOTE: pointer must be released later

			delete json_value;

			return result;
		}
		catch (const exception & e)
		{
			cout << e.what() << endl;
			return 0;
		}
	}

	/**
	 * Get country name of given location.
	 *
	 * @param coord location.
	 * @return country name.
	 *
	 * @exceptsafe This function does not throw exceptions.
	 */
	static inline wstring GetCountryName(LatLon coord)
	{
		try
		{
			string query = "[out:csv(\"name:en\")];is_in(" + to_string(coord.lat) + "," + to_string(coord.lon) + ");area._[admin_level=\"2\"];out;";

			string data = GetResponse(query);

			//cout << endl << data << endl;

			// get second line(ignore first line and third line)
			size_t start = data.find('\n');
			size_t end = data.find('\n', start + 1);

			// string to wstring
			wstring country;
			for (size_t i = start + 1; i < end; i++)
				country += data[i];
			return country;
		}
		catch (const exception&)
		{
			return L"";
		}
	}
};


#endif // OVERPASSAPI_H