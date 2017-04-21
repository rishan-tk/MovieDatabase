#pragma once

#include <map>

#include "Movie.h"

//Stores a list of movies
class MovieDatabase
{
public:
	MovieDatabase();
	~MovieDatabase();

	void mdb_initialise(const std::string fileName);
	void mdb_updateRatings(const std::string title, const uint16_t rating);
	void mdb_calculateRatings();

	friend std::istream &operator>>(std::istream& input, MovieDatabase& mdb);
	friend std::ostream &operator<<(std::ostream& output, const MovieDatabase& mdb);

private:
	void mdb_readFromFile(const std::string fileName);

	std::map<std::string, Movie*> _mdb_listOfMovies;
};

//Inline Overloaded Operator functions 
inline std::istream& operator>>(std::istream& input, MovieDatabase& mdb){
	Movie tempMovie;
	//Loop through each line in the file
	while (input >> tempMovie)
		mdb._mdb_listOfMovies.insert(std::pair<std::string, Movie*> (tempMovie.m_getTitle(), new Movie(tempMovie)));
	
	return input;
}

inline std::ostream& operator<<(std::ostream& output, const MovieDatabase& mdb){
	for (auto const& movie : mdb._mdb_listOfMovies)
		output << *movie.second;

	return output;
}
