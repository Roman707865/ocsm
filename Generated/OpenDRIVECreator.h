
#ifndef OPENDRIVECREATOR_H
#define OPENDRIVECREATOR_H
#include <all_includes.h>
#include <string>
#include <vector>
#include <memory>
#include <string>
#include "IFileReader.h"
// #include "MeasurementReader.h"
// #include "LocalFilesDatabaseConnector.h"

class MeasurementReader
{
public:
	MeasurementReader() {};
	virtual ~MeasurementReader() {};
	OCSMTypes::MeasurementContent Read(std::string file_path) {
		return OCSMTypes::MeasurementContent{};
	}

};


using OCSMTypes::OpenDRIVEContent;
using OCSMTypes::VehiclePose;
using OCSMTypes::MeasurementContent;
using OCSMTypes::GeoCoordinates;

using OCSMUtils::EgoTrajectoryCreator;
using OCSMUtils::TrajectorySpliter;
using OCSMUtils::TrajectoryToRoadMatcher;
using OCSMUtils::ReferenceLineCreator;
using OCSMUtils::ReferenceLineFusor;
using OCSMUtils::RoadBuilder;
using OCSMUtils::RoadFusor;

GeoCoordinates VehiclePoseToGeoCoordinate(const VehiclePose&)
{
	return GeoCoordinates{};
}

class OpenDRIVECreator
{
public:
	/**
	 * @param  file_path
	 */
	void SetMeasurement(std::string file_path)
	{
		measurement_file_path = file_path;
	}

	void Process() {
		auto measurement_content = measurement_reader.Read(measurement_file_path);
		EgoTrajectoryCreator trajectory_creator{};
		auto vehicle_trajectory = trajectory_creator.ComputeTrajectory(measurement_content);
		TrajectorySpliter splitter;
		auto splitted_trajectory = splitter.Split(vehicle_trajectory);
		for (const auto& trajectory : splitted_trajectory)
		{
			GeoCoordinates first_point = VehiclePoseToGeoCoordinate(trajectory.at(0));
			if (m_database_connector.IsThereAlreadyAFileFor(first_point))
			{
				OpenDRIVEContent odr_content = m_database_connector.ObtainFileFor(first_point);
				TrajectoryToRoadMatcher trajectory_matcher(odr_content);
				if (trajectory_matcher.MatchingRoadForTrajectory(trajectory) == 0)
				{
					AddNewRoadToOpenDriveContent(odr_content, trajectory, measurement_content);
				}
				else
				{
					EditExistingRoadToOpenDRIVEContent(odr_content, trajectory, measurement_content);
				}

			}
			else
			{
				CreateOpenDriveContent(trajectory, measurement_content);

			}
		}
	}


	/**
	 */
	void UpdateDatabase()
	{
	}


	/**
	 * @param  external_source_provider
	 */
	void SetExternalSourceProvider(std::vector<std::shared_ptr<ExternalSourceProvider>> external_source_provider)
	{
		m_external_source_provider = external_source_provider;
	}

private:
	// Private attributes
	//  

//     OSMMRequestHandler osmm_request_handler;
	std::string measurement_file_path;
	MeasurementReader measurement_reader;
	LocalFilesDatabaseConnector m_database_connector;
	std::vector<std::shared_ptr<ExternalSourceProvider>> m_external_source_provider;


	void CreateOpenDriveContent(const std::vector<OCSMTypes::VehiclePose>& trajectory, const OCSMTypes::MeasurementContent& measurement_content) {
		ReferenceLineCreator reference_line_creator(m_external_source_provider);
		auto reference_line = reference_line_creator.Create(trajectory, measurement_content);
		RoadBuilder road_builder(m_external_source_provider);
		auto odr_content = road_builder.Build(reference_line, trajectory, measurement_content);


	}
	void AddNewRoadToOpenDriveContent(const OCSMTypes::OpenDRIVEContent&, const std::vector<OCSMTypes::VehiclePose> trajectory, const OCSMTypes::MeasurementContent& measurement_content);
	void EditExistingRoadToOpenDRIVEContent(OCSMTypes::OpenDRIVEContent& odr_content, const std::vector<OCSMTypes::VehiclePose> trajectory, OCSMTypes::MeasurementContent& measurement_content) {
		ReferenceLineCreator reference_line_creator(m_external_source_provider);
		auto reference_line = reference_line_creator.Create(trajectory, measurement_content);
		TrajectoryToRoadMatcher trajectory_matcher(odr_content);
		auto matching_road_reference_line = trajectory_matcher.GetReferenceLineOfMatchingRoad(trajectory);
		ReferenceLineFusor reference_line_fusor;
		auto fused_line = reference_line_fusor.Fuse(matching_road_reference_line, reference_line);
		RoadBuilder road_builder(m_external_source_provider);
		auto built_odr_content = road_builder.Build(fused_line, trajectory, measurement_content);
		RoadFusor road_fusor;
		auto fused_content = road_fusor.Fuse(odr_content, built_odr_content);

	}

};

#endif // OPENDRIVECREATOR_H

