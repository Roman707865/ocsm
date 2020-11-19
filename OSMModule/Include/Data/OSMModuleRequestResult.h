#ifndef OSMMODULEREQUESTRESULT_H
#define OSMMODULEREQUESTRESULT_H

#include "RequestStatus.h"
#include "RoadPart.h"

struct OSMModuleRequestResult
{
	RequestStatus request_status;
	vector<RoadPart> road_parts;

public:
	OSMModuleRequestResult()
	{
	}

	OSMModuleRequestResult(RequestStatus request_status)
	{
		this->request_status = request_status;
	}
};

#endif // OSMMODULEREQUESTRESULT_H