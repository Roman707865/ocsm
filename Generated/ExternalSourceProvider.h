#ifndef EXTERNALSOURCEPROVIDER_H
#define EXTERNALSOURCEPROVIDER_H
#include <../all_includes.h>
#include <vector>
class ExternalSourceProvider
{
public:
	/**
	 * @return OCSMTypes::ExternalRoadData
	 * @param  geocoordinates
	 */
	ExternalSourceProvider() {}
	virtual ~ExternalSourceProvider() {}
	virtual OCSMTypes::ExternalRoadData RequestInformationFor(std::vector<OCSMTypes::GeoCoordinates> geocoordinates) = 0;
};

#endif // EXTERNALSOURCEPROVIDER_H