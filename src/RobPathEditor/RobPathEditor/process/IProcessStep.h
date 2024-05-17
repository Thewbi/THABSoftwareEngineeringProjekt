#pragma once

#include <ProcessContext.h>

namespace kuka_generator
{
    /// <summary>
    /// This is the "interface" that has to be implemented by each ProcessStep.
    /// This class cannot exist by itself meanung you cannot create a variable from it.
    /// Instead, a class has to be derived from it. This class may then be used to create variables
    /// The purpose of this class is it to enforce the existance of the process() method in each ProcessStep variable!
    ///
    /// https://stackoverflow.com/questions/318064/how-do-you-declare-an-interface-in-c
    ///
    /// Whenever you add a new folder and filter in the project explorer tree, do not forget to add the
    /// folder to the VC++ input directories via the project properties!
    /// </summary>
    class IProcessStep
    {

    public:

        virtual ~IProcessStep() {}

        /// <summary>
        /// Start/Run the process
        /// </summary>
        virtual void process() = 0;

    };
}
