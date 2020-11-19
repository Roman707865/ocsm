/* 
 * This file is part of OSMM module and implemention of RequestLauncher submodule.
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

#include "RequestLauncher.h"
#include <iostream>
#include "OverpassAPI.h"

/**
* Process a request.
*
* @param request OSMModuleRequest.
* @return JSON result array.
*
* @except This function throw Exception.
 */
vector<JSONValue*> RequestLauncher::Process(OSMModuleRequest request) 
{
	this->sub_requests = request.poses.size();

	vector<JSONValue*> result; // NOTE: pointers must be released later
	result.reserve(this->sub_requests);

	cout << "======== " << this->sub_requests << " sub requests are processed ========" << endl;

	for (size_t i = 0; i < this->sub_requests; ++i)
	{
		const VehiclePos& pos = request.poses[i];
		const LatLon& coord = pos.coord;

		cout << "Proceeding vehicle pos : " << i 
			<< " lat " << coord.lat 
			<< " lon " << coord.lon
			<< " heading " << pos.heading << endl;

		cout << "Connecting..." << endl;

		/* connecting to server and getting result */
		try
		{
			JSONValue* json = OverpassAPI::GetWayData(coord);

			if (json == 0 || json->AsArray().empty())
				cout << "No ways" << endl;
			else
				cout << json->AsArray().size() << " ways" << endl;

			result.push_back(json); // Considering SLR3, SLR4, SLR5, SLR6

			this->request_status = SUCCESS;

			this->total_request_count++;
		}
		catch (const exception & e)
		{
			cout << "Connect failed" << endl;

			this->request_status = FAILED;

			throw Exception(e); // SLR7

			return result;
		}
	}

	return result;
}
