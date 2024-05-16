#pragma once

namespace kuka_generator
{
    constexpr unsigned int MATRIX_3X3F_ELEMENT_COUNT = 9;

    /// <summary>
    /// https://de.mathworks.com/help/matlab/math/basic-matrix-operations.html
    ///
    /// Row-major Matrix, the same as matlab uses.
    /// In Matlab, typing in: A = [1 2 0; 2 5 -1; 4 10 -1]
    /// yields the matrix
    /// A = 3×3
    ///    1     2     0
    ///    2     5    -1
    ///    4    10    -1
    ///
    /// Same as with this class:
    /// Matrix3x3f A(1, 2, 0, 2, 5, -1, 4, 10, -1);
    /// </summary>
    class Matrix3x3f
    {

    public:

        float data[MATRIX_3X3F_ELEMENT_COUNT]{ 0.0 };

        /// <summary>
        /// The default constructor. This constructor creates the identity matrix
        /// 1 0 0
        /// 0 1 0
        /// 0 0 1
        /// </summary>
        Matrix3x3f()
        {
            data[0] = data[4] = data[8] = 1.0f;
        }

        /// <summary>
        /// Matrix3x3f A(1, 2, 0, 2, 5, -1, 4, 10, -1);
        /// yields the matrix
        ///    1     2     0
        ///    2     5    -1
        ///    4    10    -1
        /// </summary>
        /// <param name="m0">first row, element 0</param>
        /// <param name="m1">first row, element 1</param>
        /// <param name="m2">first row, element 2</param>
        /// <param name="m3">second row, element 0</param>
        /// <param name="m4">second row, element 1</param>
        /// <param name="m5">second row, element 2</param>
        /// <param name="m6">third row, element 0</param>
        /// <param name="m7">third row, element 1</param>
        /// <param name="m8">third row, element 2</param>
        Matrix3x3f(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
        {
            data[0] = m0;
            data[1] = m1;
            data[2] = m2;

            data[3] = m3;
            data[4] = m4;
            data[5] = m5;

            data[6] = m6;
            data[7] = m7;
            data[8] = m8;
        }

        /// <summary>
        /// This is the so-called copy constructor. It defines the behavior of this class
        /// should the user apply the assignment operator to it using another matrix called
        /// rhs (right-hand side) as an argument.
        /// 
        /// </summary>
        /// <param name="rhs">The matrix that is assigned to this class.</param>
        /// <returns></returns>
        Matrix3x3f& operator=(const Matrix3x3f& rhs)
        {
            for (int i = 0; i < MATRIX_3X3F_ELEMENT_COUNT; i++)
            {
                data[i] = rhs.data[i];
            }
            return *this;
        }

        /// <summary>
        /// Assignment operator for a specific element using the indexing operator [i]
        /// </summary>
        /// <param name="i">picks the location of data where the matrix's data[] is accessed</param>
        /// <returns></returns>
        float& operator[](unsigned int i)
        {
            if (i < MATRIX_3X3F_ELEMENT_COUNT)
            {
                return data[i];
            }
        }

    };
}
