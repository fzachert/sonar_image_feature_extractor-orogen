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



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See ImageProcessing.hpp for more detailed
// documentation about them.

bool ImageProcessing::configureHook()
{
    if (! ImageProcessingBase::configureHook())
        return false;
	
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
