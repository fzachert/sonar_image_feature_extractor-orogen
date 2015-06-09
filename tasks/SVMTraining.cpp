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
    
    started = false;
    finished = false;
    clusters.clear();
    labels.clear();
    
    positives = 0;
    negatives = 0;
    
    svm_conf = _svm_config.get();
    svm_conf.learn = true;
    
    classifier.init(svm_conf);
    
    return true;
}
void SVMTraining::updateHook()
{
    SVMTrainingBase::updateHook();
    
    LabeledCluster lc;
    
    while( _labeled_cluster.read(lc) == RTT::NewData){
      
      if(!started){
	started = true;
      }
      
      last_time = base::Time::now();
      
      if(lc.label.label_id > 0){
	positives++;
      }else if( lc.label.label_id < 0){
	negatives++;
	lc.label.label_id = 2.0;
      }
      
      clusters.push_back( lc.cluster);
      labels.push_back( lc.label);      
      
    }
    
    if( started && (base::Time::now().toSeconds() - last_time.toSeconds()) > _timeout.get() && !finished){
      
      std::cout << "----------------------------" << std::endl;
      std::cout << "Reading Data complete" << std::endl;
      std::cout << "Got " << clusters.size() << " samples with " << positives << " positives and " << negatives << " negatives." << std::endl;
      
      finished = true;
      svm_conf.weights.clear();
      svm_conf.weights.push_back(1.0);
      svm_conf.weights.push_back( ((double)positives) / ((double)negatives) );
      svm_conf.weight_labels.clear();
      svm_conf.weight_labels.push_back(1.0);
      svm_conf.weight_labels.push_back(2.0);
      
      SVMConfig sconf = classifier.learn( clusters, labels);
      std::cout << "Learning Finished" << std::endl;
      _svm_config.set( sconf);

      
    }
    
}

