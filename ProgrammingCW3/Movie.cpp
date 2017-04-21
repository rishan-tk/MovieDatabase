#include "Movie.h"



Movie::Movie()
{
}

Movie::Movie(std::string title, uint16_t releaseYear, std::string ageRating, std::string genre, uint16_t runTime, uint16_t meanRating, uint16_t noOfRatings){
	_m_title = title;
	_m_releaseYear = releaseYear;
	_m_ageRating = ageRating;
	_m_genre = genre;
	_m_runTime = runTime;
	_m_meanRating = meanRating;
	_m_noOfRatings = noOfRatings;
}

Movie::Movie(const Movie& movie){
	_m_title = movie.m_getTitle();
	_m_releaseYear = movie.m_getReleaseYear();
	_m_ageRating = movie.m_getAgeRating();
	_m_genre = movie.m_getGenre();
	_m_runTime = movie.m_getRunTime();
	_m_meanRating = movie.m_getMeanRating();
	_m_noOfRatings = movie.m_getNoOfRatings();

}



Movie::~Movie()
{
}






