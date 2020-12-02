#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <iostream>
#include <../Generated/OCSMTypes/VehiclePose.h>
#include <vector>

using namespace std;

namespace OCSMTypes
{
	class FileReader
	{
	public:
		/*csv-file_path read*/
		vector<VehiclePose> OpenFile(const string & file_path, int point_count);
	};
#endif // FILEREADER_H
}

