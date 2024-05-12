#pragma once
#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <NEPolygon.h>

#include "Vec.hpp"

namespace nep
{
    enum struct LightId : int
    {
        LIGHT0 = 0,
        LIGHT1 = 1,
        LIGHT2 = 2,
        LIGHT3 = 3
    };

    template<LightId mUnderlying, int id = (int)mUnderlying>
    struct Light
    {
        Light(uint32_t color, const Vec3f& pos)
        {
            NE_LightSet(id, color, pos.x, pos.y, pos.z);
        }
        Light(uint32_t color, const Vec3i& pos)
        {
            NE_LightSetI(id, color, pos.x, pos.y, pos.z);
        }
        ~Light()
        {
            NE_LightOff(id);
        }

        void SetColor(uint32_t color)
        {
            NE_LightSetColor(id, color);
        }
    };
}

#endif