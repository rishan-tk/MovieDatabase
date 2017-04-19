#pragma once

#include <cstdint>


//Overload arithmetic/relation operators

class TimeStamp
{
public:
	TimeStamp();
	~TimeStamp();

private:
	std::uint8_t _day, _month;
	std::uint16_t _year;
	std::uint8_t _hour, _minute, _second;
};

