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

#ifdef _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif

#include "RequestLauncher.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

#else

#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#endif // _WIN32

#define RANGE					0.00003;
#define OVERPASS_HOST			"www.overpass-api.de"
#define OVERPASS_PORT			80
#define JSON_PATH				"Results.json"

const int buf_size = 10 * 1024;// 1M

LatLon temp_pos{ 0, 0 };

fstream fout;

 /**
 * Output connect result of RequestLauncher submodule.
 *
 * @param values contain user's OSMModuleRequest.
 * @return number of subrequest.
 *
 * @exceptsafe This function does not throw exceptions.
 */
Launcher_Out RequestLauncher::Output(OSMModuleRequest request)
{

	

	Launcher_Out out;

	double lat = 0, lon = 0;

	size_t subrequest_cnt=0;

	fout.open(JSON_PATH, ios::out);

	around = RANGE;

	cout << "*****" << request.poses_buf.size() << " subrequests are created.******" << endl;

	subrequest_cnt = request.poses_buf.size();

	res.resize(subrequest_cnt);
	out.JsonArray.resize(subrequest_cnt);

	country.resize(subrequest_cnt);
	out.country.resize(subrequest_cnt);

	for (size_t i = 0; i < request.poses_buf.size(); ++i) 
	{
		
			cout << "Proceeding vehicle pos " << i << " long "
				<< request.poses_buf[i].latlon.longitude << " lat "
				<< request.poses_buf[i].latlon.latitude << " heading "
				<< request.poses_buf[i].heading<<endl;

			lat = request.poses_buf[i].latlon.latitude;
			lon = request.poses_buf[i].latlon.longitude;

	
			temp_pos = LatLon{ lon, lat };

			/*make request query*/
			string query = Create_Query(temp_pos);

		   /*connecting to server and saving result */
		   
			if (Get_CountryName(i, temp_pos) < 0)
			{
				
				cout << "connect failed." << endl;

			}

			if (Get_Json(i, query) < 0 )
			{
				res[i] = NULL;

				cout << "connect failed." << endl;
			}

			out.JsonArray[i] = res[i];
			out.country[i] = country[i];
			out.pos = temp_pos;
	}

	fout.close();

	return out;
}

/**
 * Create query of given GPS point.
 *
 * @param values contain GPS position.
 * @return created query string.
 *
 * @exceptsafe This function does not throw exceptions.
 */

string RequestLauncher::Create_Query(LatLon pos)
{
	string query;

	double lat1, lon1, lat2, lon2;

	lat1 = pos.latitude - around;
	lon1 = pos.longitude - around;

	lat2 = pos.latitude + around;
	lon2 = pos.longitude + around;

	string str_lat1 = to_string(lat1);
	string str_lon1 = to_string(lon1);

	string str_lat2 = to_string(lat2);
	string str_lon2 = to_string(lon2);

	string comma = ",";

	/*Http request header*/
	string queryStart = "GET /api/interpreter?data=[out:json];(node(";

	/*Http request tail*/
	string queryEnd = ");node(w)->.x;);out; HTTP/1.1\r\n"
		"Host: www.overpass-api.de\r\n"
		"User-Agent: star\r\n"
		"Accept: */*\r\n"
		"Connection: close\r\n"
		"\r\n";

	string query1 = str_lat1;
	string query2 = str_lon1;
	string query3 = str_lat2;
	string query4 = str_lon2;

	string way = ");way(";

	/*box : boundary rectengle*/
	string box = query1 + comma + query2 + comma + query3 + comma + query4;

	query = queryStart + box + way + box + queryEnd;

	//cout << query;

	return query;
}

/**
 * Output connect result of RequestLauncher submodule.
 *
 * @param values contain user's OSMModuleRequest.
 * @return number of subrequest.
 *
 * @exceptsafe This function does not throw exceptions.
 */

int RequestLauncher::Get_Json(size_t id, string query)
{
	
	cout << "connecting.....\n";

	try
	{

#ifdef _WIN32
		WSADATA wsadata;

		int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);

		if (iResult != NO_ERROR)
			printf("\nmy ERROR at WSAStartup()\n");
#endif

		auto sock = socket(AF_INET, SOCK_STREAM, 0);

		if (sock == -1)
		{
			perror("error opening socket"); return -1;
		}

		hostent* remoteHost = gethostbyname(OVERPASS_HOST);

		in_addr addr;
		addr.s_addr = *(u_long*)remoteHost->h_addr_list[0];

		struct sockaddr_in sin;

		sin.sin_port = htons(OVERPASS_PORT);

		sin.sin_addr.s_addr = inet_addr(inet_ntoa(addr));

		sin.sin_family = AF_INET;

		if (connect(sock, (struct sockaddr*) & sin, sizeof(sin)) == -1)
		{
			perror("error connecting to host"); return -1;
		}

		const int query_len = (int)query.length() + 1; // trailing '\0'

		if (send(sock, query.c_str(), query_len, 0) != query_len)
		{
			perror("error sending query"); return -1;
		}

		vector<char> json_buf(buf_size, '\0');
		vector<char> buf(buf_size, '\0');

		int pos = 0;

		while (true)
		{
			const int recv_len = recv(sock, &buf[pos], buf_size - 1, 0);
			
			if (recv_len == -1)
			{
				perror("error receiving response");

				return -1;
			}
			else if (recv_len == 0)
			{
				cout << endl; break;
			}
			else
			{
				pos = pos + recv_len;
			}

			
		}
		
		json_buf = Get_JSON_Body(buf,id);
		
		//cout << &json_buf[0];
	
		res[id] = JSON::Parse(json_buf.data());
		
		fout << "\n";

		fout << json_buf.data();
		
	}
	catch (const exception&)
	{
		return -1;
	}

	// WinExec("notepad database.json", 1);
	return 1;
}

/**
 * This function remove  HTTP header in Http response string.
 *
 * @param values contain entire  Http response string.
 * @return JSON body string.
 *
 * @exceptsafe This function does not throw exceptions.
 */

vector<char> RequestLauncher::Get_JSON_Body(vector<char> buf, size_t id)
{
	vector<char> jbody(buf_size, '\0');

	long pos = -1;
	bool  flag = false;
	int num = 0;


	for (size_t i = 0; i < buf_size-2; i++)
	{
		if (buf[i] == '\n' && buf[i+1]=='0' )
		{
			break;
		}

		if (buf[i] == '{')
		{
			flag = true;
			num++;
		}
		
		if (flag)
		{
			pos++;
			jbody[pos] = buf[i];
		}
		
		/*if (num == 1)
		{
			string temp ="\
							\"country\" : \"";
			
			for (size_t j = 0; j < temp.size(); j++)
			{
				pos++;

				jbody[pos] = temp.data()[j];
			}

			for (size_t j = 0; j < country[id].size(); j++)
			{
				pos++;

				jbody[pos] = country[id].data()[j];
			}

			pos++;
			jbody[pos] = '\"';
			
			num++;
		}*/
			
		
	}


	return jbody;
}
/**
 * Get country name of given location.
 *
 * @param values contain user's OSMModuleRequest.
 * @return number of subrequest.
 *
 * @exceptsafe This function does not throw exceptions.
 */

int RequestLauncher::Get_CountryName(size_t id, LatLon pos)
{
	string comma = ",";

	string query;
	query = "[out:csv(\"name:en\")];is_in(" + to_string(pos.latitude) + comma + to_string(pos.longitude) + ");area._[admin_level=\"2\"];out;";
	/*Http request header*/
	string queryStart = "GET /api/interpreter?data=";

	/*Http request tail*/
	string queryEnd = " HTTP/1.1\r\n"
		"Host: www.overpass-api.de\r\n"
		"User-Agent: star\r\n"
		"Accept: */*\r\n"
		"Connection: close\r\n"
		"\r\n";
	query = queryStart + query + queryEnd;
		

	try
	{

#ifdef _WIN32
		WSADATA wsadata;

		int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);

		if (iResult != NO_ERROR)
			printf("\nmy ERROR at WSAStartup()\n");
#endif

		auto sock = socket(AF_INET, SOCK_STREAM, 0);

		if (sock == -1)
		{
			perror("error opening socket"); return -1;
		}

		hostent* remoteHost = gethostbyname(OVERPASS_HOST);

		in_addr addr;
		addr.s_addr = *(u_long*)remoteHost->h_addr_list[0];

		struct sockaddr_in sin;

		sin.sin_port = htons(OVERPASS_PORT);

		sin.sin_addr.s_addr = inet_addr(inet_ntoa(addr));

		sin.sin_family = AF_INET;

		if (connect(sock, (struct sockaddr*) & sin, sizeof(sin)) == -1)
		{
			perror("error connecting to host"); return -1;
		}

		const int query_len = (int)query.length() + 1; // trailing '\0'

		if (send(sock, query.c_str(), query_len, 0) != query_len)
		{
			perror("error sending query"); return -1;
		}

		vector<char> buf(buf_size, '\0');

		while (true)
		{
			
			const int recv_len = recv(sock, &buf[0], buf_size - 1, 0);

			if (recv_len == -1)
			{
				perror("error receiving response");

				return -1;
			}
			else if (recv_len == 0)
			{
				cout << endl; break;
			}
			else
			{
				string str;
				
				str.append(&buf[0]);
				
				int lineNo = 8;
				
				string line;
				
				istringstream stream(str);
				
				while (lineNo-- >= 0)
					 getline(stream, line);
				
				//cout << line <<endl;

				country[id] = line;

			}


		}
	}
	catch (const exception&)
	{
		return -1;
	}
	return 1;
}