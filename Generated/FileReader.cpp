#include "FileReader.h"


#define USE_DEFAULT_VALUES		1
#define DEFAULT_CSV_FILEPATH	"F:\\Work\\osm\\osm\\swift-gnss.csv"
#define DEFAULT_POINTCOUNT		10


using namespace OCSMTypes;
using namespace std;

wstring StringToWString(const string& s)
{
	wstring temp(s.length(), L' ');
	copy(s.begin(), s.end(), temp.begin());
	return temp;
}

vector<VehiclePose>FileReader::OpenFile(const string & file_path, int point_count)
{
	cout << "Reading data from csv_file...." << endl;

	file_path = DEFAULT_CSV_FILEPATH;

	vector<VehiclePose>buffer;
		buffer.reserve(point_count);
		
	ifstream fin(file_path);
	if (!fin.is_open())
		return buffer;

	string line;
	getline(fin, line);

	/* read by one line */
	while (getline(fin, line))
	{
		line += ',';

		VehiclePose poses;
		int field_index = 0;
		size_t prev_pos = 0;

		while (true)
		{
			size_t cur_pos = line.find(',', prev_pos);
			if (cur_pos == string::npos)
				break;

			if (cur_pos != prev_pos)
			{
				if (field_index == 8) {
					poses.time = StringToWString(line.substr(prev_pos, cur_pos - prev_pos));
				}
				else if (field_index == 9) {
					poses.coord.latitude = stod(line.substr(prev_pos, cur_pos - prev_pos));
				}
				else if (field_index == 10) {
					poses.coord.longitude = stod(line.substr(prev_pos, cur_pos - prev_pos));
				}
				else if (field_index == 16) {
					poses.roll = stod(line.substr(prev_pos, cur_pos - prev_pos));
				}
				else if (field_index == 17) {
					poses.pitch = stod(line.substr(prev_pos, cur_pos - prev_pos));
				}
				else if (field_index == 18)
					poses.yaw = stod(line.substr(prev_pos, cur_pos - prev_pos));
			}

			field_index++;
			prev_pos = cur_pos + 1;
		}
		buffer.push_back(poses);
		if (buffer.size() >= point_count)
			break;
	}
	return buffer;
}


