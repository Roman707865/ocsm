#ifndef DRIVINGDIRECTION_H
#define DRIVINGDIRECTION_H

#include <string>

enum DrivingDirection
{
	POSITIVE,
	NEGATIVE,
	BOTH
};

static inline wstring GetDrivingDirectionString(DrivingDirection driving_direction)
{
	static wstring driving_directions[] =
	{
		L"POSITIVE",
		L"NEGATIVE",
		L"BOTH"
	};

	return driving_directions[(int)driving_direction];
}

#endif // DRIVINGDIRECTION_H