#ifndef ROADMARKINGCOLOR_H
#define ROADMARKINGCOLOR_H

#include <xstring>

enum RoadMarkingColor
{
	WHITE,
	YELLOW,
	RED,
	GREEN,
	BLUE
};

static inline wstring GetRoadMarkingColorString(RoadMarkingColor road_marking_color)
{
	static wstring road_marking_colors[]
	{
		L"WHITE",
		L"YELLOW",
		L"RED",
		L"GREEN",
		L"BLUE"
	};

	return road_marking_colors[(int)road_marking_color];
}

#endif // ROADMARKINGCOLOR_H