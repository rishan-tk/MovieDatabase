#pragma once

#include <vector>

#include "Movie.h"

//Stores a list of movies
class MovieDatabase
{
public:
	MovieDatabase();
	~MovieDatabase();

private:
	std::vector<Movie> _listOfMovies;
};

