//
// Created by PervyGod on 13-12-2024.
//

#ifndef DATA_H
#define DATA_H
#include<list>
#include<string>

class Data {
	std::string _key{};
	std::string _value{};
public:
	Data() = default;
	Data(const std::string& key,const std::string& value) :_key{ key }, _value{ value } {};
	~Data() = default;
	std::pair<std::string, std::string> get()const;
	void set(const std::pair<std::string, std::string>&);
	friend std::ostream& operator<< (std::ostream & out, const Data&);
	friend std::istream& operator>>(std::istream& in, Data&);
	friend std::fstream& operator<<(std::fstream& out, const Data&);
	friend std::fstream& operator>>(std::fstream& in, Data&);
};



#endif //DATA_H
