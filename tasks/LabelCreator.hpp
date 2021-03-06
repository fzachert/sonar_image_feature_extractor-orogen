/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef SONAR_IMAGE_FEATURE_EXTRACTOR_LABELCREATOR_TASK_HPP
#define SONAR_IMAGE_FEATURE_EXTRACTOR_LABELCREATOR_TASK_HPP

#include "sonar_image_feature_extractor/LabelCreatorBase.hpp"
#include <sonar_image_feature_extractor/ClassificationTypes.hpp>
#include <sonar_image_feature_extractor/SonarProcessing.hpp>

namespace sonar_image_feature_extractor {

    /*! \class LabelCreator 
     * \brief The task context provides and requires services. It uses an ExecutionEngine to perform its functions.
     * Essential interfaces are operations, data flow ports and properties. These interfaces have been defined using the oroGen specification.
     * In order to modify the interfaces you should (re)use oroGen and rely on the associated workflow.
     * 
     * \details
     * The name of a TaskContext is primarily defined via:
     \verbatim
     deployment 'deployment_name'
         task('custom_task_name','sonar_image_feature_extractor::LabelCreator')
     end
     \endverbatim
     *  It can be dynamically adapted when the deployment is called with a prefix argument. 
     */
    class LabelCreator : public LabelCreatorBase
    {
	friend class LabelCreatorBase;
    protected:

	SonarProcessing detector;

    public:
        /** TaskContext constructor for LabelCreator
         * \param name Name of the task. This name needs to be unique to make it identifiable via nameservices.
         * \param initial_state The initial TaskState of the TaskContext. Default is Stopped state.
         */
        LabelCreator(std::string const& name = "sonar_image_feature_extractor::LabelCreator", TaskCore::TaskState initial_state = Stopped);

        /** TaskContext constructor for LabelCreator 
         * \param name Name of the task. This name needs to be unique to make it identifiable for nameservices. 
         * \param engine The RTT Execution engine to be used for this task, which serialises the execution of all commands, programs, state machines and incoming events for a task. 
         * \param initial_state The initial TaskState of the TaskContext. Default is Stopped state.
         */
        LabelCreator(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state = Stopped);

        /** Default deconstructor of LabelCreator
         */
	~LabelCreator();

        /** This hook is called by Orocos when the state machine transitions
         * from PreOperational to Stopped. If it returns false, then the
         * component will stay in PreOperational. Otherwise, it goes into
         * Stopped.
         *
         * It is meaningful only if the #needs_configuration has been specified
         * in the task context definition with (for example):
         \verbatim
         task_context "TaskName" do
           needs_configuration
           ...
         end
         \endverbatim
         */
        bool configureHook();

        bool startHook();

        void updateHook();

    };
}

#endif

