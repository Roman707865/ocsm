#ifndef OSMINTERNAL_H
#define OSMINTERNAL_H

#include "OSMModule.h"

struct AnalyzerResult
{
	RoadInfo** roadinfo_buf;
	int way_count[1000];
	size_t req_num;
};

#endif // OSMINTERNAL_H
