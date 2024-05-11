#include <nep/FileSystem.hpp>

#include <iostream>

#include <filesystem.h>
#include <nds.h>

using namespace nep;

FileSystem::FileSystem()
{
    //
}

void FileSystem::init(const std::string& romfile)
{
    // Initialize nitroFS
    if (!nitroFSInit(romfile.c_str()))
    {
        printf("\x1B[31mFailed to start nitroFS\n");
        printf("\x1B[31mPlease reset the system\n");

        while (1)
        {
            swiWaitForVBlank();
        }
    }
}

File FileSystem::get(const std::string& path) const
{
    return File(path);
}

File::File() {}
File::File(const std::string& path)
{
    openBytes(path);
}

File::~File()
{
    close();
}

void File::openBytes(const std::string& path)
{
    mHandle = fopen(path.c_str(), "rb");
}
void File::readAllBytes(std::vector<uint8_t>& content)
{
    auto len = length();
    content.resize(len);

    uint8_t* entireFile = content.data();
    entireFile[len] = 0;
    auto bytesRead = fread(entireFile, 1, len, std::bit_cast<FILE*>(mHandle));
    sassert(bytesRead == len, "Fatal error whilst reading file!");
}
void File::openText(const std::string& path)
{
    mHandle = fopen(path.c_str(), "r");
}
void File::readAllText(std::string& content)
{
    auto len = length();
    content.resize(len);

    char* entireFile = content.data();
    entireFile[len] = 0;
    auto bytesRead = fread(entireFile, 1, len, std::bit_cast<FILE*>(mHandle));
    sassert(bytesRead == len, "Fatal error whilst reading file!");
}
void File::close()
{
    if(mHandle != nullptr)
        fclose(std::bit_cast<FILE*>(mHandle));
}

std::size_t File::length() const
{
    fseek(std::bit_cast<FILE*>(mHandle), 0, SEEK_END);
    auto len = ftell(std::bit_cast<FILE*>(mHandle));
    fseek(std::bit_cast<FILE*>(mHandle), 0, SEEK_SET);
    return len;
}

/*
FILE* inf = fopen("nitro:/test.txt","rb");
    if(inf)
    {
        size_t len;

        fseek(inf,0,SEEK_END);
        len = ftell(inf);
        fseek(inf,0,SEEK_SET);

        char *entireFile = (char*)malloc(len+1);
        entireFile[len] = 0;
        if(fread(entireFile,1,len,inf) != len)
            printf("savage error reading the bytes from the file!\n");
        else
            printf("%s\n",entireFile);
        free(entireFile);

        fclose(inf);
    }
    */