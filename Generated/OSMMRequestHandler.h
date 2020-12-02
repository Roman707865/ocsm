
#ifndef OSMMREQUESTHANDLER_H
#define OSMMREQUESTHANDLER_H

#include <../all_includes.h>
// #include "ExternalSourceProvider.h"
// #include "OCSMTypes/ExternalRoadData.h"
class OSMMRequestHandler : virtual public ExternalSourceProvider
{
public:
	OCSMTypes::ExternalRoadData RequestInformationFor(std::vector<OCSMTypes::GeoCoordinates> geocoordinates)
		override {
		return OCSMTypes::ExternalRoadData{};
	}
};

#endif // OSMMREQUESTHANDLER_H
