//
// Created by PervyGod on 13-12-2024.
//
#include <cstdio>
#include"Data.h"
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<vector>

#define FILE "data.dat"

extern int test();

void readRecord(std::vector<Data>&,std::fstream&);
void printRecord(const std::vector<Data>&);
void writeRecord(std::vector<Data>&,std::fstream&);

int main()
{
    
    test();
    std::vector<Data>records{};

    if (std::fstream file(FILE, std::ios::in | std::ios::binary);file.is_open())
    {
        //read
        readRecord(records, file);
        printRecord(records);
        file.close();
        return 0;
    };

    if (std::fstream file(FILE, std::ios::out | std::ios::binary);file.is_open())
    {
        //write
        writeRecord(records, file);
        printRecord(records);
        file.close();
        return 0;
    };

    return 0;
};


void readRecord(std::vector<Data>& records, std::fstream& file)
{
    while (true)
    {
        Data data{};
        file >> data;
        if (file.eof())break;
        records.push_back(data);
    };
};

void printRecord(const std::vector<Data>&records)
{
    for (const Data& record : records)
    {
        std::cout << record << "\n";
    };
}

void writeRecord(std::vector<Data>&records, std::fstream&file)
{
    int flag{};
    do
    {
        Data data{};
        std::cin >> data;
        records.push_back(data);
        file << data;
        std::cout << "would you like to add more data ? Any NonZero input for no ? ";
        std::cin >> flag;
        std::cin.clear();
        std::cin.ignore();

    } while (!flag);
}