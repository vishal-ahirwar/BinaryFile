
// Auto Genrated C++ file by aura CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#define FILE_NAME "test.bin"
#define MAX_ALLOWED_SIZE 1024 * 1024
bool readString(std::string &out)
{
    std::fstream file(FILE_NAME, std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        size_t size{};
        file.read(reinterpret_cast<char *>(&size), sizeof size);
        if (size > MAX_ALLOWED_SIZE)
            return false;
        out.resize(size);
        if (file.read(const_cast<char *>(out.c_str()), size))
            return true;
        return false;
    };
    return false;
};
bool writeString(const std::string &str)
{
    std::fstream file(FILE_NAME, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        size_t size{str.length()};
        file.write(reinterpret_cast<char *>(&size), sizeof size);
        file.write(str.c_str(), str.length());
        return true;
    };
    return false;
}
int main(int argc, char *argv[])
{
    if (std::string str; readString(str))
    {
        std::cout << str << std::endl;
        return 0;
    };
    if (std::string str; std::getline(std::cin, str), writeString(str))
    {
        std::cout << str << std::endl;
        return 0;
    };
    std::cout << "error" << std::endl;
    return 0;
};
