#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP

namespace nep
{
    enum struct EngineMode
    {
        NEP_3D = 1 << 0,
        NEP_DUAL_3D = 1 << 1,
        NEP_DUAL_3D_FB = 1 << 2,
        NEP_DUAL_3D__DMA = 1 << 3,
        NEP_CONSOLE = 1 << 4
    };

    struct Engine
    {
        
    };
}

#endif