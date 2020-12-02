#ifndef MEASUREMENTCONTENT_H
#define MEASUREMENTCONTENT_H

#include <../Generated/OCSMTypes/VehiclePose.h>
#include <JSONValue.h>
/*
	measurement content structure is JSONvalue 
	measurement content in www 	structure 
*/

namespace OCSMTypes {

	class MeasurementContent
	{
		
	public:
		// Public attributes
		//  Add variable
		vector<MeasurementContent> measurement_content(vector<VehiclePose> &pos, JSONValue* json_data);

	}; // end of package namespace
}
#endif // MEASUREMENTCONTENT_H

