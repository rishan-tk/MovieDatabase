#include "Movie.h"



Movie::Movie(std::string title, uint16_t releaseYear, std::string ageRating, std::string genre, uint16_t runTime, uint8_t meanRating, uint16_t noOfRatings){
	_m_title = title;
	_m_releaseYear = releaseYear;
	_m_ageRating = ageRating;
	_m_genre = genre;
	_m_runTime = runTime;
	_m_meanRating = meanRating;
	_m_noOfRatings = noOfRatings;
}



Movie::~Movie()
{
}

void Movie::m_incrementNoOfRatings(){
	_m_noOfRatings++;
}
