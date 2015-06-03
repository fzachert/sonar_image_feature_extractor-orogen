/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "SVMTraining.hpp"

using namespace sonar_image_feature_extractor;

SVMTraining::SVMTraining(std::string const& name, TaskCore::TaskState initial_state)
    : SVMTrainingBase(name, initial_state)
{
}

SVMTraining::SVMTraining(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : SVMTrainingBase(name, engine, initial_state)
{
}

SVMTraining::~SVMTraining()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See SVMTraining.hpp for more detailed
// documentation about them.

bool SVMTraining::configureHook()
{
    if (! SVMTrainingBase::configureHook())
        return false;
    return true;
}
bool SVMTraining::startHook()
{
    if (! SVMTrainingBase::startHook())
        return false;
    return true;
}
void SVMTraining::updateHook()
{
    SVMTrainingBase::updateHook();
}
void SVMTraining::errorHook()
{
    SVMTrainingBase::errorHook();
}
void SVMTraining::stopHook()
{
    SVMTrainingBase::stopHook();
}
void SVMTraining::cleanupHook()
{
    SVMTrainingBase::cleanupHook();
}
