#pragma once
#ifndef MODEL_HPP
#define MODEL_HPP

#include "Animation.hpp"
#include "Material.hpp"

#include <NEModel.h>

namespace nep
{
    struct Model
    {
        Model(NE_ModelType type = NE_ModelType::NE_Static)
        {
            mUnderlying = NE_ModelCreate(type);
        }
        ~Model()
        {
            NE_ModelDelete(mUnderlying);
        }

        void SetMaterial(const Material& material)
        {
            NE_ModelSetMaterial(mUnderlying, material.Unwrap());
        }

        void SetAnimation(const Animation& animation)
        {
            NE_ModelSetAnimation(mUnderlying, animation.Unwrap());
        }

        bool LoadDSMFAT(const char* path)
        {
            return NE_ModelLoadDSMFAT(mUnderlying, path) == 1;
        }
        
        bool LoadStaticMesh(const void* meshData, const uint8_t modelBin[])
        {
            return NE_ModelLoadStaticMesh(mUnderlying, modelBin) == 1;
        }

        void Rotate(Vec3i rot)
        {
            NE_ModelRotate(mUnderlying, rot.x, rot.y, rot.z);
        }

        void Draw()
        {
            NE_ModelDraw(mUnderlying);
        }

        void SetPosition(Vec3i pos)
        {
            NE_ModelSetCoord(mUnderlying, pos.x, pos.y, pos.z);
        }

        void SetScale(Vec3i size)
        {
            NE_ModelScale(mUnderlying, size.x, size.y, size.z);
        }

    private:
        NE_Model* mUnderlying{};
    };
}

#endif