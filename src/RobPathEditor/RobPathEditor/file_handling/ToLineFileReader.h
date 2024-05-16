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

        ToLineFileReader(std::string path_to_file, IToLineFileReaderCallback& callback);

        int process();

    };
}
