#pragma once
#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <NETexture.h>

namespace nep
{
    struct Material
    {
        Material()
        {
            mUnderlying = NE_MaterialCreate();
        }
        ~Material()
        {
            NE_MaterialDelete(mUnderlying);
        }

        bool TexLoad(NE_TextureFormat fmt, int sizeX, int sizeY, NE_TextureFlags flags, const void* texture)
        {
            return NE_MaterialTexLoad(mUnderlying, fmt, sizeX, sizeY, flags, texture) == 1;
        }
        bool TexLoadFAT(NE_TextureFormat fmt, int sizeX, int sizeY, NE_TextureFlags flags, const char* path)
        {
            return NE_MaterialTexLoadFAT(mUnderlying, fmt, sizeX, sizeY, flags, path) == 1;
        }

        NE_Material* Unwrap() const
        {
            return mUnderlying;
        }

    private:
        NE_Material* mUnderlying{};
    };
}

#endif