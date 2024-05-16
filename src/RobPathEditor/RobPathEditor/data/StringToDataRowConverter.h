#pragma once

#include <DataRow.h>
#include <string>

namespace kuka_generator
{
    class StringToDataRowConverter
    {

    public:

        void convert(std::string, DataRow& data_row);

    };
}
