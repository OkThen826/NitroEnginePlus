#pragma once
#ifndef CORE_HPP
#define CORE_HPP

namespace nep
{
    namespace Core
    {
        //Static storage for singleton instances
        template<typename inst_t>
        static constexpr auto& get()
        {
            static std::unique_ptr<inst_t> instance = std::make_unique<inst_t>();
            return instance;
        }
    };
}

#endif