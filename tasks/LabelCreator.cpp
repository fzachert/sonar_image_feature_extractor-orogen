/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "LabelCreator.hpp"

using namespace sonar_image_feature_extractor;

LabelCreator::LabelCreator(std::string const& name, TaskCore::TaskState initial_state)
    : LabelCreatorBase(name, initial_state)
{
}

LabelCreator::LabelCreator(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : LabelCreatorBase(name, engine, initial_state)
{
}

LabelCreator::~LabelCreator()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See LabelCreator.hpp for more detailed
// documentation about them.

bool LabelCreator::configureHook()
{
    if (! LabelCreatorBase::configureHook())
        return false;
    return true;
}
bool LabelCreator::startHook()
{
    if (! LabelCreatorBase::startHook())
        return false;
    return true;
}
void LabelCreator::updateHook()
{
    LabelCreatorBase::updateHook();
    
    base::samples::SonarScan scan;
    LabeledCluster lc;
    Label l;
    DebugData dd;
    
    while(_input_scans.read(scan) == RTT::NewData){
      
      if(_id != 0.0){
	l.pos = _pos.get();
	l.label_id = _id.get();
	
	lc = detector.label_cluster(scan, config, dd,  l);
	
	if( lc.label.label_id != 0.0){
	  _labeled_cluster.write(lc);
	}
	
      }
      
    }   
    
}

