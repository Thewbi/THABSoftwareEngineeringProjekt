#include <ExampleProcessStep.h>

namespace kuka_generator
{
    // this constructor places the process_context into the member variable called
    // process_context_ via the so-called initializer list. The initializer list are
    // all the statements after the colon.
    //
    // process_context_(process_context) means that process_context_ is set to the procese_context parameter.
    ExampleProcessStep::ExampleProcessStep(kuka_generator::ProcessContext& process_context) : process_context_(process_context)
    {
        // empty
    }

    void ExampleProcessStep::process()
    {
        std::cout << "[ExampleProcessStep] start processing!" << std::endl;

        // your code goes here ...

        // example code
        process_context_.use_user_defined_velocity = true;
        process_context_.user_defined_velocity = 42069;

        std::cout << "[ExampleProcessStep] done!" << std::endl;
    }

}
