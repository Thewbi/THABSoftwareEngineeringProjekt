#include "LoadInputFileProcessStep.h"

#include <iostream>

namespace kuka_generator
{
    void LoadInputFileProcessStep::process(ProcessContext& process_context)
    {

        std::cout << "[LoadInputFileProcessStep] Reading file '" << process_context.input_file << "'" << std::endl;

        std::cout << "[LoadInputFileProcessStep] Reading file done!" << std::endl;

    }

}
