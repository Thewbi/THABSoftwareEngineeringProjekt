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
    /// </summary>
    class IProcessStep
    {

    public:

        virtual ~IProcessStep() {}

        virtual void process(ProcessContext& process_context) = 0;

    };
}
