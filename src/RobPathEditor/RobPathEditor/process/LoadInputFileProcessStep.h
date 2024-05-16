#pragma once

#include <iostream>

#include <IProcessStep.h>
#include <IToLineFileReaderCallback.h>
#include <ProcessContext.h>
#include <StringToDataRowConverter.h>
#include <ToLineFileReader.h>

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
    class LoadInputFileProcessStep : public IProcessStep, public IToLineFileReaderCallback
    {

    private:

        kuka_generator::ProcessContext& process_context_;

        kuka_generator::StringToDataRowConverter converter_;

    public:

        LoadInputFileProcessStep(kuka_generator::ProcessContext& process_context);

        void process() override;

        void process_line_callback(std::string line) override;

    };
}
