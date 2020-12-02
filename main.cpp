#include <iostream>
#include <fstream>
#include <../Generated/FileReader.h>
#include <../Generated/OCSMTypes/MeasurementContent.h>
#include <../Generated/OCSMTypes/GeoCoordinates.h>
#include <../Generated/ExternalSourceProvider.h>
#include <../Generated/OSMMRequestHandler.h>
#include <../Generated/OpenDRIVECreator.h>


#define  USE_DEFAULT_VALUES		1
#define  DEFAULT_POINTCOUNT		10
#define  MAX_POINTS_COUNT       72

using namespace std;
using namespace OCSMTypes;


/**
 * Read csv file content and save to text file .
 * 
 * @param csv file path.
 * @return none value.
 *
 * @ exceptsafe This function does not throw exceptions.
 */

 /* 
 * Main function for testing OSMM module.
 */
int main(int argc, char** argv)
{
	vector<std::shared_ptr<ExternalSourceProvider>> external_sources;

	external_sources.push_back(std::make_shared<OSMMRequestHandler>());

	OpenDRIVECreator odr_creator;
	odr_creator.SetExternalSourceProvider(external_sources);
	odr_creator.SetMeasurement("foobar.json");
	odr_creator.Process();
	
	return 0;
}
