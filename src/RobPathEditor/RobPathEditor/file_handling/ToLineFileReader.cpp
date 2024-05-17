#include <ToLineFileReader.h>

#include <fstream>
#include <iostream>

namespace kuka_generator
{

    ToLineFileReader::ToLineFileReader(std::string path_to_file, IToLineFileReaderCallback& callback) : callback_(callback)
    {
        path_to_file_ = path_to_file;
    }

    int ToLineFileReader::process()
    {
        // open the file and check if the file really exists at the specified location
        std::ifstream ifstream(path_to_file_);
        if (ifstream.fail())
        {
            std::cout << "[LoadInputFileProcessStep] File '" << path_to_file_ << "' does not exist!" << std::endl;

            // return -1 as an error code for "file does not exist"
            return -1;
        }

        for (std::string line; getline(ifstream, line); )
        {
            //std::cout << line << std::endl;
            callback_.process_line_callback(line);
        }

        // no error has occured, return 0
        return 0;
    }

}
