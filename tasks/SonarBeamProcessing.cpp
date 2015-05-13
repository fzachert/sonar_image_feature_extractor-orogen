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

bool SonarBeamProcessing::setBlur(boost::int32_t value)
{
  config.blur = value;
  
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setBlur(value));
}


bool SonarBeamProcessing::setCluster_max_size(boost::int32_t value)
{
  config.cluster_max_size = value;
  
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setCluster_max_size(value));
}

bool SonarBeamProcessing::setCluster_min_size(boost::int32_t value)
{
  config.cluster_min_size = value;
  
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setCluster_min_size(value));
}

bool SonarBeamProcessing::setCluster_noise(boost::int32_t value)
{
  config.cluster_noise = value;
  
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setCluster_noise(value));
}

bool SonarBeamProcessing::setDebug_mode(::sonar_image_feature_extractor::DEBUG_MODE const & value)
{
  config.debug_mode = value;
  
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setDebug_mode(value));
}

bool SonarBeamProcessing::setThreshold(double value)
{
  
  config.threshold = value;
  
 return(sonar_image_feature_extractor::SonarBeamProcessingBase::setThreshold(value));
}

/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See SonarBeamProcessing.hpp for more detailed
// documentation about them.

bool SonarBeamProcessing::configureHook()
{
    if (! SonarBeamProcessingBase::configureHook())
        return false;
    
    config.blur = _blur.get();
    config.debug_mode = _debug_mode.get();
    config.threshold = _threshold.get();
    config.cluster_min_size = _cluster_min_size.get();
    config.cluster_max_size = _cluster_max_size.get();
    config.cluster_noise = _cluster_noise.get();
    
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
    config.debug_mode = _debug_mode.get();
    
    while(_sonar_image.read(input) == RTT::NewData){
      
      SonarFeatures feat = detector.detect(input, debug, config);
      
      _debug_frame.write(debug);
      
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
