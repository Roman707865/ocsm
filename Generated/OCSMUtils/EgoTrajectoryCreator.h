
#ifndef EGOTRAJECTORYCREATOR_H
#define EGOTRAJECTORYCREATOR_H
#include <../all_includes.h>
#include <vector>

using OCSMTypes::MeasurementContent;

namespace OCSMUtils {

	class EgoTrajectoryCreator
	{
	public:
		/**
		 * @return std::vector<OCSMTypes::VehiclePose>
		 * @param  measurements
		 */
		std::vector<VehiclePose> ComputeTrajectory(const MeasurementContent& measurements)
		{

		}

	};
} // end of package namespace

#endif // EGOTRAJECTORYCREATOR_H

