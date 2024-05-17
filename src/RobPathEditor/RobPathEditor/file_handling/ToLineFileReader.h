#pragma once

#include <string>
#include <vector>

#include <IToLineFileReaderCallback.h>

namespace kuka_generator
{
    class ToLineFileReader
    {

    private:

        std::string path_to_file_;

        IToLineFileReaderCallback& callback_;

    public:

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="path_to_file">The file to read from</param>
        /// <param name="callback">The callback to place lines into</param>
        ToLineFileReader(std::string path_to_file, IToLineFileReaderCallback& callback);

        /// <summary>
        /// Start reading the file.
        /// </summary>
        /// <returns>-1 if the file is not found</returns>
        int process();

    };
}
