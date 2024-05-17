#pragma once

#include <DataRow.h>
#include <sstream>
#include <string>

namespace kuka_generator
{
    /// <summary>
    /// Convert the string-form of a DataRow into a DataRow object.
    ///
    /// The advantage of this class is to have the entire conversion logic
    /// in a single class that has a single purpose only.
    /// </summary>
    class StringToDataRowConverter
    {

    public:

        /// <summary>
        /// Performs the conversion
        /// </summary>
        /// <param name="data_row_as_string">the string</param>
        /// <param name="data_row">the DataRow object to fill with the data from the string</param>
        void convert(std::string data_row_as_string, DataRow& data_row);

    };
}
