#ifndef ROADMARKING_H
#define ROADMARKING_H

#include <string>

enum RoadMarking
{
	NONE,
	CONTINUOUS,
	DASHED,
	DOUBLED // instead of DOUBLE, to avoid error
};

static inline wstring GetRoadMarkingString(RoadMarking road_marking)
{
	static wstring road_markings[] =
	{
		L"NONE",
		L"CONTINUOUS",
		L"DASHED",
		L"DOUBLED" // instead of DOUBLE, to avoid error
	};

	return road_markings[(int)road_marking];
}

#endif // ROADMARKING_H