#pragma once
#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>

namespace nep
{
    struct File;
    struct FileSystem
    {
        FileSystem();
        void init(const std::string& romfile);
        File get(const std::string& path) const;
    private:
    };

    struct File
    {
        File();
        File(const std::string& path);
        ~File();

        void openBytes(const std::string& path);
        void openText(const std::string& path);
        void readAllText(std::string& content);
        void close();

        std::size_t length() const;
    private:
        void* mHandle = 0;
    };
}

#endif