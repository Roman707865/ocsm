
#include "OSMModule.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define USE_DEFAULT_VALUES		1
#define DEFAULT_CSV_FILEPATH	"C:\\Users\\Star\\Documents\\GitHub\\fvrr_vmwork_cmake\\swift-gnss.csv"
#define DEFAULT_POINTCOUNT		1

const string data_path = "data.txt";



/**
 * Read csv file content and save to text file .
 *
 * @param csv file path.
 * @return none value .
 *
 * @exceptsafe This function does not throw exceptions.
 */
void read_csv(const string &csv_path)
{



	cout << "reading data from csv file..." << endl;

	/* number of input GPS measure point */
	int point_count = 0;

	fstream fout;

	/* open csv file */
	ifstream fin(csv_path);

	fout.open(data_path, ios::out);

	vector<vector<string>> fields;

	if (fin)
	{
		string line;

		point_count = 0;

		/* read by one line */
		while (getline(fin, line))
		{
			/* GPS point counting */
			point_count++;

			stringstream sep(line);

			string field;

			fields.push_back(vector<string>());

			if (point_count > 1)
			{
				while (getline(sep, field, ','))
				{
					fields.back().push_back(field);
				}
			}
		}
	}

	for (auto row : fields)
	{
		int i = 0;
		for (auto field : row)
		{
			i++;
			if (i == 10 || i == 11)
			{
				if (field != "")
				{
					// 	cout << field << ' ';

					fout << field << '\n';
				}
			}
		}

		// 	cout << '\n';
	}

	fout.close();
}

/*
 * Main function for testing OSMM module.
 */
int main(int argc, char** argv)
{
#if USE_DEFAULT_VALUES == 1
	string csv_path = DEFAULT_CSV_FILEPATH;
	int point_count = DEFAULT_POINTCOUNT;
#else
	string csv_path;
	int point_count = -1;
#endif

	if (argc > 1)
	{
		csv_path = argv[1];

		if (argc > 2)
		{
			point_count = atoi(argv[2]);
		}
	}

	if (csv_path.empty())
	{
		cout << "Plase input correct csv file path for first argument !" << endl;
		return 0;
	}

	if (point_count <= 0 || point_count > 70)
	{
		cout << "Plase input correct point count(>0 and <=70) for second argument !" << endl;
		return 0;
	}

	OSMModuleRequest request{};

	read_csv(csv_path);

	fstream fin;

	fin.open(data_path, ios::in);

	vector<VehiclePos> posebuffer(point_count);
	//42.476472, -71.220167
	for (int i = 0; i < point_count; i++) // read data from text file
	{
		fin >> posebuffer[i].latlon.latitude;
		fin >> posebuffer[i].latlon.longitude;

		posebuffer[i].latlon.latitude= 42.476472;
		posebuffer[i].latlon.longitude= -71.220167;
		posebuffer[i].heading = 90;
	}

	request.poses_buf = posebuffer;

	fin.close();

	/* send request to server and process */
	OSMModuleRequestResult result = RequestDataForPath(request);

	/*Test result output*/
	cout << "Looking at result" << endl;

	if (result.request_status == RequestStatus::SUCCESS)
	{
		cout << "Success." << endl;

		cout << "The result contain " << result.road_info.size() << " RoadPart" << endl;
		// cout<<"The first road part has "<<result.roadpart_buf[0].lanesection_buf.size() <<" Lane Sections"<<endl;
		// cout<<"The first lane section has "<<result.roadpart_buf[0].lanesection_buf[0].lanes_buf.size()<<" Lanes"<<endl;
	

		for (size_t i = 0; i < result.road_info.size(); ++i)
		{
			cout << "--------------Characteristics of Road" << i << "--------------------" << endl;
			cout<<"country : "<< result.road_info[i].country  << endl;
			wcout << L"name : " << result.road_info[i].name << endl;
			wcout << L"highway : " << result.road_info[i].highway << endl;
			wcout << L"lanes : " << result.road_info[i].lanes << endl;
			wcout << L"lit : " << result.road_info[i].lit << endl;
			wcout << L"maxspeed : " << result.road_info[i].maxspeed << endl;
			wcout << L"smoothness : " << result.road_info[i].smoothness << endl;
			wcout << L"surface : " << result.road_info[i].surface << endl;
			wcout << L"width : " << result.road_info[i].width << endl;
			for (size_t j = 0; j < result.roadpart_buf[i].lanesection_buf[0].lanes_buf.size(); j++)
			{
				cout << " -----Lane " << j << " property" << endl;
				cout << " width : " << result.roadpart_buf[i].lanesection_buf[0].lanes_buf[j].width << endl;
				cout << " speedlimit : " << result.roadpart_buf[i].lanesection_buf[0].lanes_buf[j].speedlimit << endl;
				cout << " direction : " << result.roadpart_buf[i].lanesection_buf[0].lanes_buf[j].driving_direction << endl;
				cout << " lateraloffset : " << result.roadpart_buf[i].lanesection_buf[0].lanes_buf[j].lateraloffset << endl;
			}
		}
	}
	else if (result.request_status == RequestStatus::NOTFOUND)
	{
		cout << "Not found." << endl;
	}
	else if (result.request_status == RequestStatus::FAILED)
	{
		cout << "Failed." << endl;
	}

	cout << endl << "End" << endl;

	while (1)
	{
	}
	return 0;
}
