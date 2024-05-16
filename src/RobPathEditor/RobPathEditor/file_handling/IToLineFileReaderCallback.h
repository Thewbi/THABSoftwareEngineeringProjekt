#pragma once

#include <string>

namespace kuka_generator
{
    /// <summary>
    /// This is the "interface" that has to be implemented by each FileReaderCallback.
    /// This class cannot exist by itself meanung you cannot create a variable from it.
    /// Instead, a class has to be derived from it. This class may then be used to create variables
    /// The purpose of this class is it to enforce the existance of the process() method in each FileReaderCallback variable!
    ///
    /// https://stackoverflow.com/questions/318064/how-do-you-declare-an-interface-in-c
    /// </summary>
    class IToLineFileReaderCallback
    {

    public:

        virtual ~IToLineFileReaderCallback() {}

        virtual void process_line_callback(std::string line) = 0;

    };
}
