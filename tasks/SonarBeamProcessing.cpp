/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "SonarBeamProcessing.hpp"

using namespace sonar_image_feature_extractor;

SonarBeamProcessing::SonarBeamProcessing(std::string const& name, TaskCore::TaskState initial_state)
    : SonarBeamProcessingBase(name, initial_state)
{
}

SonarBeamProcessing::SonarBeamProcessing(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : SonarBeamProcessingBase(name, engine, initial_state)
{
}

SonarBeamProcessing::~SonarBeamProcessing()
{
}

bool SonarBeamProcessing::setCluster_max_size(boost::int32_t value)
{
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setCluster_max_size(value));
}

bool SonarBeamProcessing::setCluster_min_size(boost::int32_t value)
{
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setCluster_min_size(value));
}

bool SonarBeamProcessing::setCluster_noise(boost::int32_t value)
{
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setCluster_noise(value));
}

bool SonarBeamProcessing::setDebug_mode(::sonar_image_feature_extractor::DEBUG_MODE const & value)
{
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setDebug_mode(value));
}

bool SonarBeamProcessing::setThreshold(double value)
{
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setThreshold(value));
}

/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See SonarBeamProcessing.hpp for more detailed
// documentation about them.

bool SonarBeamProcessing::configureHook()
{
    if (! SonarBeamProcessingBase::configureHook())
        return false;
    return true;
}
bool SonarBeamProcessing::startHook()
{
    if (! SonarBeamProcessingBase::startHook())
        return false;
    return true;
}
void SonarBeamProcessing::updateHook()
{
    SonarBeamProcessingBase::updateHook();
}
void SonarBeamProcessing::errorHook()
{
    SonarBeamProcessingBase::errorHook();
}
void SonarBeamProcessing::stopHook()
{
    SonarBeamProcessingBase::stopHook();
}
void SonarBeamProcessing::cleanupHook()
{
    SonarBeamProcessingBase::cleanupHook();
}
