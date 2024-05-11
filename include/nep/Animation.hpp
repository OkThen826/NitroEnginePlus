#pragma once
#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <NEAnimation.h>

namespace nep
{
    struct Animation
    {
        Animation()
        {
            mUnderlying = NE_AnimationCreate();
        }

        Animation(const Animation&) = delete;
        Animation& operator=(const Animation&) = delete;

        ~Animation()
        {
            NE_AnimationDelete(mUnderlying);
        }

        bool LoadFAT(const char* path)
        {
            return NE_AnimationLoadFAT(this->Unwrap(), path) == 1;
        }

        NE_Animation* Unwrap() const
        {
            return mUnderlying;
        }
    private:
        NE_Animation* mUnderlying;
    };
}

#endif