//
// Created by PervyGod on 13-12-2024.
//

#include "Data.h"
#include<iostream>
#include<fstream>
#define MAX_SIZE 1024*1024
void Data::set(const std::pair<std::string, std::string>& data)
{
	if (data.first.empty() || data.second.empty())return;
	_key = data.first;
	_value = data.second;
};

std::pair<std::string, std::string> Data::get()const
{
	return { _key,_value };
};

std::ostream& operator<<(std::ostream& out, const Data& data)
{
	// TODO: insert return statement here
	out << data._key << ", " << data._value;
	return out;
};

std::istream& operator>>(std::istream& in, Data& data)
{
	// TODO: insert return statement here
	std::cout << "key ? ";
	std::getline(in, data._key);
	std::cout << "value ?";
	std::getline(in, data._value);
	return in;
};

std::fstream& operator<<(std::fstream& file, const Data&data)
{
	// TODO: insert return statement here
	size_t size{ data._key.length() };
	file.write(reinterpret_cast<char*>(&size), sizeof(size));
	file.write(data._key.c_str(), size);
	size = data._value.length();
	file.write(reinterpret_cast<char*>(&size), sizeof(size));
	file.write(data._value.c_str(), size);
	return file;
}

std::fstream& operator>>(std::fstream& file, Data&data)
{
	// TODO: insert return statement here
	size_t size{};
	if (!file.read(reinterpret_cast<char*>(&size), sizeof(size)))return file;
	if (size > MAX_SIZE)
	{
		std::cout << "error : data file corrupted!\n";
		std::exit(-1);
	};
	char* buffer{ new char[size + 1] };
	if (!file.read(buffer, size))return file;
	if (!buffer)return file;
	buffer[size] = '\0';
	data._key={ buffer };
	delete[]buffer;
	if (!file.read(reinterpret_cast<char*>(&size), sizeof(size)))return file;
	if (size > MAX_SIZE)
	{
		std::cout << "error : data file corrupted!\n";
		std::exit(-1);
	};
	buffer = new char[size + 1];
	if (!file.read(buffer, size))return file;
	buffer[size] = '\0';
	data._value={ buffer };
	delete[]buffer;
	return file;
}
