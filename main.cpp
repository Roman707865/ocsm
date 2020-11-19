
#include "OSMModule.h"
#include <iostream>
#include <fstream>

#define USE_DEFAULT_VALUES		0
#define DEFAULT_CSV_FILEPATH	"C:\\_\\fvrr_vmwork\\fvrr_vmwork_cmake\\swift-gnss.csv"
#define DEFAULT_POINTCOUNT		2

/**
 * Read csv file content and save to text file .
 *
 * @param csv file path.
 * @return none value .
 *
 * @exceptsafe This function does not throw exceptions.
 */
vector<VehiclePos> read_csv(const string &csv_path, int point_count)
{
	cout << "Reading data from csv file..." << endl;

	vector<VehiclePos> posebuffer;
	posebuffer.reserve(point_count);

	/* open csv file */
	ifstream fin(csv_path);
	if (!fin.is_open())
		return posebuffer;

	string line;
	getline(fin, line);

	/* read by one line */
	while (getline(fin, line))
	{
		line += ',';

		VehiclePos pos;
	
		int field_index = 0;
		size_t prev_pos = 0;
		while (true)
		{
			size_t cur_pos = line.find(',', prev_pos);
			if (cur_pos == string::npos)
				break;

			if (cur_pos != prev_pos)
			{
				if (field_index == 9)
					pos.coord.lat = stod(line.substr(prev_pos, cur_pos - prev_pos));
				else if (field_index == 10)
					pos.coord.lon = stod(line.substr(prev_pos, cur_pos - prev_pos));
				else if (field_index == 18)
					pos.heading = stod(line.substr(prev_pos, cur_pos - prev_pos));
			}

			field_index++;
			prev_pos = cur_pos + 1;
		}

		posebuffer.push_back(pos);
		if (posebuffer.size() >= point_count)
			break;
	}

	return posebuffer;
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

	if (point_count <= 0 || point_count > MAX_POINTS_COUNT)
	{
		cout << "Plase input correct point count(>0 and <=" << MAX_POINTS_COUNT << ") for second argument !" << endl;
		return 0;
	}

	OSMModuleRequest request;

	request.poses = read_csv(csv_path, point_count);

	/* send request to server and process */
	OSMModuleRequestResult result = RequestDataForPath(request);

	return 0;
}
