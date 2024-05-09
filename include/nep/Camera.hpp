#pragma once
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <NECamera.h>
#include <iostream>

#include "Vec.hpp"

namespace nep
{
    struct Camera
    {
        Camera()
        {
            mUnderlying = NE_CameraCreate();
        }

        void Set(const Vec3i& position, const Vec3i& look, const Vec3i& up = Vec3i{ 0, 1, 0 })
        {
            NE_CameraSet(mUnderlying,
                    position.x, position.y, position.z,  // Position x y z
                    look.x, look.y, look.z,  // Look at
                    up.x, up.y, up.z); 
        }

        void Use()
        {
            NE_CameraUse(mUnderlying);
        }

    private:
        NE_Camera* mUnderlying{};

        static Camera* instance;
    };
}

#endif