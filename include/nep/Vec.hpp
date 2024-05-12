#pragma once
#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>
#include <cstddef>

namespace nep
{
    struct Vec3i
    {
        Vec3i(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

        void lerp(const Vec3i& other, float t)
        {
            x = std::lerp(x, other.x, t);
            y = std::lerp(y, other.y, t);
            z = std::lerp(z, other.z, t);
        }

        union
        {
            struct
            {
                int x, y, z;
            };
            int data[3];
        };
    };

    struct Vec3f
    {
        Vec3f(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
        Vec3f(const Vec3i& other) : x(other.x), y(other.y), z(other.z) {}
        operator Vec3i() { return Vec3i{ static_cast<int>(x), static_cast<int>(y), static_cast<int>(z) }; }
        
        void lerp(const Vec3f& other, float t)
        {
            x = std::lerp(x, other.x, t);
            y = std::lerp(y, other.y, t);
            z = std::lerp(z, other.z, t);
        }

        union
        {
            struct
            {
                float x, y, z;
            };
            float data[3];
        };
    };
}

#endif