#pragma once

#include <string>
#include <cstdint>
#include <vector>

class Rating
{
public:
	Rating();
	~Rating();

private: 
	std::string _authorName; //Name of the person who submitted the review
	std::string _movieTitle;
	std::uint8_t _userRating;
	
};

class Ratings
{
public:

private:
	std::vector<Rating> _listOfRatings;

};

