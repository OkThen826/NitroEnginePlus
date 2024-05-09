#pragma once
#ifndef VEC_HPP
#define VEC_HPP

#include <cstddef>

namespace nep
{
    struct Vec3i
    {
        Vec3i(int x = 0, int y = 0, int z= 0) : x(x), y(y), z(z) {}

        union
        {
            struct
            {
                int x, y, z;
            };
            int data[3];
        };
    };
}

#endif