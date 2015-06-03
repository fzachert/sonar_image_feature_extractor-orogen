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




/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See SonarBeamProcessing.hpp for more detailed
// documentation about them.

bool SonarBeamProcessing::configureHook()
{
    if (! SonarBeamProcessingBase::configureHook())
        return false;
    
    svm_config = _svm_config.get();
    
    return true;
}
bool SonarBeamProcessing::startHook()
{
    if (! SonarBeamProcessingBase::startHook())
        return false;
    
    detector.init();
    
    return true;
}
void SonarBeamProcessing::updateHook()
{
    SonarBeamProcessingBase::updateHook();
    
    
    base::samples::SonarScan input, debug;
    DebugData dd;
    
    while(_sonar_image.read(input) == RTT::NewData){
      
      SonarFeatures feat = detector.detect(input, debug, config, dd);
      
      _debug_frame.write(debug);
      _debug_data.write(dd);
      
      _detected_buoy.write(feat);
      
    }
    
    
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
