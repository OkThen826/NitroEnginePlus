#pragma once
#ifndef MODEL_HPP
#define MODEL_HPP

#include "Animation.hpp"
#include "Material.hpp"
#include "Vec.hpp"

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

        //Don't copy models! The underlying pointer is NOT SHARED!
        Model(const Model&) = delete;
        Model& operator=(const Model&) = delete;

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
        
        bool LoadStaticMesh(const void* meshData)
        {
            return NE_ModelLoadStaticMesh(mUnderlying, meshData) == 1;
        }

        void Rotate(const Vec3i& rot)
        {
            NE_ModelRotate(mUnderlying, rot.x, rot.y, rot.z);
        }

        void Draw() const
        {
            NE_ModelDraw(mUnderlying);
        }

        void SetPosition(const Vec3i& pos)
        {
            NE_ModelSetCoord(mUnderlying, pos.x, pos.y, pos.z);
        }

        void SetScale(const Vec3i& size)
        {
            NE_ModelScale(mUnderlying, size.x, size.y, size.z);
        }

        void SetScale(const Vec3f& size)
        {
            NE_ModelScale(mUnderlying, size.x, size.y, size.z);
        }

        void SetX(int x) {
            mUnderlying->x = x;
        }

        void SetY(int y) {
            mUnderlying->y = y;
        }
        
        void SetZ(int z) {
            mUnderlying->z = z;
        }

    private:
        NE_Model* mUnderlying{};
    };
}

#endif