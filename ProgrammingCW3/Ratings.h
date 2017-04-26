#pragma once

#include <vector>

#include "TimeCode.h"

/*****************************************
*				Legend                   *
*________________________________________*
*                                        *
*   r_ = belongs to rating class         *
* _ before variables = private variable  *
*                                        *
*****************************************/

class Ratings
{
public:
	Ratings();
	~Ratings();

	std::string r_getAuthorName() const;
	std::string r_getMovieTitle() const;
	std::uint16_t r_getUserRating() const;

	friend std::istream& operator>>(std::istream& input, Ratings& r);
	friend std::ostream& operator<<(std::ostream& output, Ratings& r);

private: 
	TimeStamp _r_timeStamp;
	std::string _r_authorName; //Name of the person who submitted the review
	std::string _r_movieTitle;
	std::uint16_t _r_userRating;
	
};

//Inline Accessor functions (variables not to be modified)
inline std::string Ratings::r_getAuthorName() const { return _r_authorName; }
inline std::string Ratings::r_getMovieTitle() const { return _r_movieTitle; }
inline std::uint16_t Ratings::r_getUserRating() const { return _r_userRating; }

//Inline Overloaded Operator functions
inline std::istream& operator>>(std::istream& input, Ratings& r) {

	//Extract the time and date from the input 
	input >> r._r_timeStamp;

	//Temporary string to hold current line
	std::string tempString;
	std::smatch tempStringArray;

	//Store the line from input into tempString
	std::getline(input, tempString);

	//Check if string is empty
	if (tempString.empty())
		return input;

	//Perform regex on tempString to extract the information we need
	std::regex delimiter("\"(.+?)\",\"(.+?)\",([[:d:]]{1,2})");

	//Perform regex search operation on tempString and store substrings into tempStringArray
	bool found = std::regex_search(tempString, tempStringArray, delimiter);

	//If file doesn't match the regular expression then return
	if (!found) {
		std::cout << "Entry doesn't follow the correct format!" << std::endl;
		return input;
	}

	r._r_authorName = tempStringArray[1];
	r._r_movieTitle = tempStringArray[2];
	r._r_userRating = (uint16_t)std::stoi(tempStringArray[3]);
	
	return input;
}

//Rating not const incase we want to do casting on _r_timeStamp
inline std::ostream& operator<<(std::ostream& output, Ratings& r) {
	output << r._r_timeStamp << ",\"";
	output << r._r_authorName << "\",\"";
	output << r._r_movieTitle << "\",";
	output << r._r_userRating << "\n";

	return output;
}



