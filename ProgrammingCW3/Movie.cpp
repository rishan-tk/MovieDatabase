#include "Movie.h"



Movie::Movie()
{
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






