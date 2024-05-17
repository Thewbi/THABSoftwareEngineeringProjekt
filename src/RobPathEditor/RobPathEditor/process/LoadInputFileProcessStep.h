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

        /// <summary>
        /// The process context to add data into. Used to indirectly interact with other steps.
        /// </summary>
        kuka_generator::ProcessContext& process_context_;

        /// <summary>
        /// This converter is used to convert a line from the input file into a DataRow.
        /// </summary>
        kuka_generator::StringToDataRowConverter converter_;

    public:

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="process_context">The process context</param>
        LoadInputFileProcessStep(kuka_generator::ProcessContext& process_context);

        /// <summary>
        /// Run this process
        /// </summary>
        void process() override;

        /// <summary>
        /// This specific process step implements the IToLineFileReaderCallback interface
        /// so it can register itself as a callback to the ToLineFileReader because it
        /// has to convert lines to DataRows.
        /// </summary>
        /// <param name="line">The line that was read from the file.</param>
        void process_line_callback(std::string line) override;

    };
}
