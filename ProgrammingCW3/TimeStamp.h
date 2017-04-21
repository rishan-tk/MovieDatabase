#pragma once

#include <cstdint>
#include <regex>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <iomanip>

//Overload arithmetic/relation operators

class TimeStamp
{
public:
	TimeStamp();
	~TimeStamp();

	friend std::istream& operator>>(std::istream& input, TimeStamp& ts);
	friend std::ostream& operator<<(std::ostream& output, const TimeStamp& ts);

private:
	std::uint16_t _ts_day, _ts_month, _ts_year;
	std::uint16_t _ts_hour, _ts_minute, _ts_second;
};

//Inline Overloaded Operator functions
inline std::istream& operator>>(std::istream& input, TimeStamp& ts) {
	std::string tempString;
	std::smatch tempStringArray;
	
	char delimiter = ',';

	//Get the time and date from the input and return the rest
	std::getline(input, tempString, delimiter);

	//Check if string is empty
	if (tempString.empty())
		return input;

	//Perform regex on tempString to extract the information we need
	std::regex delimiter1("([[:d:]]{2})/([[:d:]]{2})/([[:d:]]{4})T([[:d:]]{2}):([[:d:]]{2}):([[:d:]]{2})Z");

	//Perform regex search operation on tempString and store substrings into tempStringArray
	bool found = std::regex_search(tempString, tempStringArray, delimiter1);

	//If file doesn't match the regular expression then return
	if (!found) {
		std::cout << "Entry doesn't follow the correct format!" << std::endl;
		return input;
	}

	ts._ts_day = (uint16_t)std::stoi(tempStringArray[1]);
	ts._ts_month = (uint16_t)std::stoi(tempStringArray[2]);
	ts._ts_year = (uint16_t)std::stoi(tempStringArray[3]);
	ts._ts_hour = (uint16_t)std::stoi(tempStringArray[4]);
	ts._ts_minute = (uint16_t)std::stoi(tempStringArray[5]);
	ts._ts_second = (uint16_t)std::stoi(tempStringArray[6]);

	return input;
}

inline std::ostream& operator<<(std::ostream& output, const TimeStamp& ts) {
	output << std::setfill('0') << std::setw(2) << ts._ts_day << "/";
	output << std::setfill('0') << std::setw(2) << ts._ts_month << "/";
	output << ts._ts_year << "T";
	output << std::setfill('0') << std::setw(2) << ts._ts_hour << ":";
	output << std::setfill('0') << std::setw(2) << ts._ts_minute << ":";
	output << std::setfill('0') << std::setw(2) << ts._ts_second << "Z";
	return output;
}



