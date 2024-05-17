#pragma once

#include <string>
#include <vector>

#include <Matrix3x3f.h>
#include <Vector3f.h>

namespace kuka_generator
{
    class DataRow
    {

    public:

        // timestamp, read from the input file
        long timestamp{ 0 };

        // stores the unfiltered position (defined by either the user or read from the input file)
        Vector3f position;

        // keep the original data intact e.g. for applying filters to the original data.
        // Therefore filtered data is copied into this member variable.
        Vector3f position_filtered;

        // stores the unfiltered orientation (defined by either the user or read from the input file)
        Matrix3x3f orientation;

        // keep the original data intact e.g. for applying filters to the original data.
        // Therefore filtered data is copied into this member variable.
        Matrix3x3f orientation_filtered;

        // velocity at that point (either defined by the user or computed dynamically given the timestamp and the distance)
        double velocity{ 0.0 };

        // if the Douglas-Peucker algorithm decides to delete a point, the point is not actually deleted.
        // The point is kept but it's alive flag is set to false
        bool alive{ true };

        // resulting euler angles as mandated by the KAKA IRL output format
        Vector3f euler_angles;
    };
}
