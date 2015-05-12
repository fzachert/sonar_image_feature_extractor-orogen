/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "ImageProcessing.hpp"

using namespace sonar_image_feature_extractor;

ImageProcessing::ImageProcessing(std::string const& name)
    : ImageProcessingBase(name)
{
}

ImageProcessing::ImageProcessing(std::string const& name, RTT::ExecutionEngine* engine)
    : ImageProcessingBase(name, engine)
{
}

ImageProcessing::~ImageProcessing()
{
}

bool ImageProcessing::setBlur(boost::int32_t value)
{
  
  config.blur = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setBlur(value));
}

bool ImageProcessing::setCluster_max_size(boost::int32_t value)
{
  config.cluster_max_size = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setCluster_max_size(value));
}

bool ImageProcessing::setCluster_min_size(boost::int32_t value)
{
  config.cluster_min_size = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setCluster_min_size(value));
}

bool ImageProcessing::setCluster_noise(boost::int32_t value)
{
  config.cluster_noise = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setCluster_noise(value));
}

bool ImageProcessing::setDebug_mode(::sonar_image_feature_extractor::DEBUG_MODE value)
{
  config.debug_mode = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setDebug_mode(value));
}

bool ImageProcessing::setMorph(boost::int32_t value)
{
  config.morph = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setMorph(value));
}

bool ImageProcessing::setSmooth_mode(::sonar_image_feature_extractor::SMOOTH_MODE value)
{
  config.smooth_mode = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setSmooth_mode(value));
}

bool ImageProcessing::setSobel(boost::int32_t value)
{
  config.sobel = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setSobel(value));
}

bool ImageProcessing::setThreshold(double value)
{
  config.threshold = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setThreshold(value));
}

bool ImageProcessing::setThreshold_mode(::sonar_image_feature_extractor::THRESHOLD_MODE value)
{
  config.threshold_mode = value;
 return(sonar_image_feature_extractor::ImageProcessingBase::setThreshold_mode(value));
}

/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See ImageProcessing.hpp for more detailed
// documentation about them.

bool ImageProcessing::configureHook()
{
    if (! ImageProcessingBase::configureHook())
        return false;
    
    config.blur = _blur.get();
    config.morph = _morph.get();
    config.sobel = _sobel.get();
    config.threshold = _threshold.get();
    config.cluster_min_size = _cluster_min_size.get();
    config.cluster_max_size = _cluster_max_size.get();
    config.cluster_noise = _cluster_noise.get();
    
    config.smooth_mode = _smooth_mode.get();
    config.debug_mode = _debug_mode.get();
    config.threshold_mode = _threshold_mode.get();
    
    config.sonar_max_range = _max_sonar_range.get();
    config.sonar_opening_angle = _sonar_opening_angle.get();
    config.ignore_min_range = _ignore_min_range.get();
	
    detector.init();
    
    return true;
}
bool ImageProcessing::startHook()
{
    if (! ImageProcessingBase::startHook())
        return false;
    return true;
}
void ImageProcessing::updateHook()
{
    ImageProcessingBase::updateHook();
    
    config.smooth_mode = _smooth_mode.get();
    config.debug_mode = _debug_mode.get();
    config.threshold_mode = _threshold_mode.get();

    base::samples::frame::Frame input, debug;
    
    while(_sonar_image.read( input) == RTT::NewData){
      
      SonarFeatures feat = detector.detect(input, debug, config);
      
      _detected_buoy.write(feat);
      
      if(_debug_mode != NO_DEBUG)
	_debug_frame.write(debug);
      
    }   
    
    
}

void ImageProcessing::stopHook()
{
    ImageProcessingBase::stopHook();
}
