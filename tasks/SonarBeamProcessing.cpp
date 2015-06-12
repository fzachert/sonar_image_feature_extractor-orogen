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
    ignore_labels = _ignore_labels.get();
    
    return true;
}
bool SonarBeamProcessing::startHook()
{
    if (! SonarBeamProcessingBase::startHook())
        return false;
    
    detector.init( svm_config);
    
    return true;
}
void SonarBeamProcessing::updateHook()
{
    SonarBeamProcessingBase::updateHook();
    
    
    base::samples::SonarScan input, debug;
    DebugData dd;
    
    while(_sonar_image.read(input) == RTT::NewData){
      

      base::Time start = base::Time::now();
      SonarFeatures feat = detector.detect(input, debug, config, dd);

      for(std::vector<Feature>::iterator it_feat = feat.features.begin(); it_feat != feat.features.end(); ){
	    
	  bool ignore = false;

	  for( std::vector<int>::iterator it_label = ignore_labels.begin(); it_label != ignore_labels.end(); it_label++){

	      if( it_feat->desc.label == *it_label){
		ignore = true;		
	      }
	      	    
	  }	  
	  
	  if(ignore){

	    it_feat = feat.features.erase(it_feat);

	  }else{
	    it_feat++;
	  }
	  
      }
      
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
