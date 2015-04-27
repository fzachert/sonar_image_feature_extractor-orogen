/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"

using namespace sonar_image_feature_extractor;

Task::Task(std::string const& name)
    : TaskBase(name)
{
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
{
}

Task::~Task()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See Task.hpp for more detailed
// documentation about them.

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;
    
      config.debug_mode = _debug_mode.get();
      config.blur = _blur.get();
      config.morph = _morph.get();
      config.sobel = _sobel.get();
      config.threshold = _threshold.get();
      config.cluster_min_size = _cluster_min_size.get();
      config.cluster_max_size = _cluster_max_size.get();
      config.cluster_noise = _cluster_noise.get();    
    
      config.ignore_min_range = _ignore_min_range.get();
      config.sonar_max_range = _max_sonar_range.get();
      config.sonar_opening_angle = _sonar_opening_angle.get();
    
    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;
    
    detector.init();
    
    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();    
    
    base::samples::frame::Frame frame, debug_frame;
    
      config.debug_mode = _debug_mode.get();
      config.smooth_mode = _smooth_mode.get();
      
      if(_sonar_image.read(frame) == RTT::NewData){
      
      SonarFeatures feat = detector.detect(frame, debug_frame, config); 
      feat.time = frame.time;
      _detected_buoy.write(feat);
      
      if(config.debug_mode != 0){
	_debug_frame.write(debug_frame);
      }
	
    }
    
}

void Task::stopHook()
{
    TaskBase::stopHook();
}

bool Task::setBlur(boost::int32_t value)
{
  config.blur = value;
 return(sonar_image_feature_extractor::TaskBase::setBlur(value));
}

bool Task::setCluster_max_size(boost::int32_t value)
{
  config.cluster_max_size = value;
 return(sonar_image_feature_extractor::TaskBase::setCluster_max_size(value));
}

bool Task::setCluster_min_size(boost::int32_t value)
{
  config.cluster_min_size = value;
 return(sonar_image_feature_extractor::TaskBase::setCluster_min_size(value));
}

bool Task::setCluster_noise(boost::int32_t value)
{
  config.cluster_noise = value;
 return(sonar_image_feature_extractor::TaskBase::setCluster_noise(value));
}

bool Task::setDebug_mode(DEBUG_MODE value)
{
  std::cout << "setDebugMode" << std::endl;
  config.debug_mode = value;
 return(sonar_image_feature_extractor::TaskBase::setDebug_mode(value));
}

bool Task::setSmooth_mode(SMOOTH_MODE value)
{
  config.smooth_mode = value;
 return(sonar_image_feature_extractor::TaskBase::setSmooth_mode(value));
}

bool Task::setMorph(boost::int32_t value)
{
  config.morph = value;
return(sonar_image_feature_extractor::TaskBase::setMorph(value));  
}

bool Task::setSobel(boost::int32_t value)
{
  config.sobel = value;
 return(sonar_image_feature_extractor::TaskBase::setSobel(value));
}

bool Task::setThreshold(double value)
{
  config.threshold = value;
 return(sonar_image_feature_extractor::TaskBase::setThreshold(value));
}



