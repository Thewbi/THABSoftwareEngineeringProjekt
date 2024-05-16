#include <LoadInputFileProcessStep.h>

namespace kuka_generator
{
    LoadInputFileProcessStep::LoadInputFileProcessStep(kuka_generator::ProcessContext& process_context) : process_context_(process_context)
    {
        // empty
    }

    void LoadInputFileProcessStep::process()
    {
        std::cout << "[LoadInputFileProcessStep] Reading file '" << process_context_.input_file << "'" << std::endl;

        // the line reader takes care of the file handling
        // Every line will be sent to the process_line_callback function
        kuka_generator::ToLineFileReader to_line_file_reader(process_context_.input_file, *this);
        to_line_file_reader.process();

        std::cout << "[LoadInputFileProcessStep] Reading file done!" << std::endl;
    }

    void LoadInputFileProcessStep::process_line_callback(std::string line)
    {
        // convert the line to a data row
        kuka_generator::DataRow data_row;
        converter_.convert(line, data_row);

        // store the data row
        process_context_.data_rows.push_back(data_row);
    }

}
