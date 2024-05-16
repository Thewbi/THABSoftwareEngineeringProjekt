#pragma once

namespace kuka_generator
{
    /// <summary>
    /// https://stackoverflow.com/questions/57810925/convenient-vector3f-class
    /// </summary>
    class Vector3f
    {

    public:

        float x{ 0.0f };
        float y{ 0.0f };
        float z{ 0.0f };

        float& operator[](unsigned int i)
        {
            if (i == 0)
            {
                return x;
            }
            if (i == 1)
            {
                return y;
            }
            if (i == 2)
            {
                return z;
            }
        }
    };
}
