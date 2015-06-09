/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "SonarProcessingBase.hpp"

using namespace sonar_image_feature_extractor;

SonarProcessingBase::SonarProcessingBase(std::string const& name, TaskCore::TaskState initial_state)
    : SonarProcessingBaseBase(name, initial_state)
{
}

SonarProcessingBase::SonarProcessingBase(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : SonarProcessingBaseBase(name, engine, initial_state)
{
}

SonarProcessingBase::~SonarProcessingBase()
{
}

bool SonarProcessingBase::setAdaptive_threshold_neighborhood(boost::int32_t value)
{
  
  config.adaptive_threshold_neighborhood = value;
  
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setAdaptive_threshold_neighborhood(value));
}


bool SonarProcessingBase::setBlur(boost::int32_t value)
{
  
  config.blur = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setBlur(value));
}

bool SonarProcessingBase::setCluster_max_size(boost::int32_t value)
{
  config.cluster_max_size = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setCluster_max_size(value));
}

bool SonarProcessingBase::setCluster_min_size(boost::int32_t value)
{
  config.cluster_min_size = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setCluster_min_size(value));
}

bool SonarProcessingBase::setCluster_noise(double value)
{
  config.cluster_noise = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setCluster_noise(value));
}

bool SonarProcessingBase::setDistance_mode(::sonar_image_feature_extractor::DISTANCE_MODE const & value)
{
  config.distance_mode = value;
  return(sonar_image_feature_extractor::SonarProcessingBaseBase::setDistance_mode(value));
}

bool SonarProcessingBase::setDebug_mode(::sonar_image_feature_extractor::DEBUG_MODE const & value)
{
  config.debug_mode = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setDebug_mode(value));
}

bool SonarProcessingBase::setMorph(boost::int32_t value)
{
  config.morph = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setMorph(value));
}

bool SonarProcessingBase::setSmooth_mode(::sonar_image_feature_extractor::SMOOTH_MODE const & value)
{
  config.smooth_mode = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setSmooth_mode(value));
}

bool SonarProcessingBase::setSobel(boost::int32_t value)
{
  config.sobel = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setSobel(value));
}

bool SonarProcessingBase::setThreshold(double value)
{
  config.threshold = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setThreshold(value));
}

bool SonarProcessingBase::setThreshold_mode(::sonar_image_feature_extractor::THRESHOLD_MODE const & value)
{
  config.threshold_mode = value;
 return(sonar_image_feature_extractor::SonarProcessingBaseBase::setThreshold_mode(value));
}

/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See SonarProcessingBase.hpp for more detailed
// documentation about them.

bool SonarProcessingBase::configureHook()
{
    if (! SonarProcessingBaseBase::configureHook())
        return false;
    
    config.blur = _blur.get();
    config.morph = _morph.get();
    config.sobel = _sobel.get();
    config.threshold = _threshold.get();
    config.adaptive_threshold_neighborhood = _adaptive_threshold_neighborhood.get();
    config.cluster_min_size = _cluster_min_size.get();
    config.cluster_max_size = _cluster_max_size.get();
    config.cluster_noise = _cluster_noise.get();
    
    config.smooth_mode = _smooth_mode.get();
    config.debug_mode = _debug_mode.get();
    config.threshold_mode = _threshold_mode.get();
    config.distance_mode = _distance_mode.get();
    
    config.sonar_max_range = _max_sonar_range.get();
    config.sonar_opening_angle = _sonar_opening_angle.get();
    config.ignore_min_range = _ignore_min_range.get(); 
    
    config.gemini = _gemini.get();
    
    return true;
}
bool SonarProcessingBase::startHook()
{
    if (! SonarProcessingBaseBase::startHook())
        return false;
    return true;
}
void SonarProcessingBase::updateHook()
{
    config.smooth_mode = _smooth_mode.get();
    config.debug_mode = _debug_mode.get();
    config.threshold_mode = _threshold_mode.get();
    config.distance_mode = _distance_mode.get();
  
  
    SonarProcessingBaseBase::updateHook();  
    
}

