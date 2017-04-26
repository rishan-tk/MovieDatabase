#include <fstream>
#include <iostream>
#include <algorithm>


#include "MovieDatabase.h"





MovieDatabase::MovieDatabase()
{
}

//Deallocate memory used for movies
MovieDatabase::~MovieDatabase(){
	for (auto movie : _mdb_listOfMovies)
		delete movie.second;
}

void MovieDatabase::mdb_initialise(const std::string fileName){
	//Check if string is empty
	if (!fileName.empty())
		readFromFile(fileName);
	else
		std::cout << "Empty file name!" << std::endl;
}

void MovieDatabase::mdb_updateRatings(const std::string title, const uint16_t rating){
	//Increment the number of ratings for the current title
	_mdb_listOfMovies.find(title)->second->m_incrementNoOfRatings();
	//Store the rating value 
	_mdb_listOfMovies.find(title)->second->m_updateMeanRatings(rating);
}

void MovieDatabase::mdb_calculateRatings(){
	for (auto movie : _mdb_listOfMovies)
		movie.second->m_calculateMeanRatings();
}

void MovieDatabase::mdb_sortbyYear(){
	std::vector<Movie*> listOfMovies;
	for (auto movie : _mdb_listOfMovies)
		listOfMovies.push_back(movie.second);

	std::sort(listOfMovies.begin(), listOfMovies.end(), [&listOfMovies](Movie* a, Movie* b) {if (*a != *b) { return a->m_getReleaseYear() < b->m_getReleaseYear(); } else { return a->m_getTitle() < b->m_getTitle(); } });

	for(Movie* movie : listOfMovies)
		std::cout << *movie;
}

void MovieDatabase::mdb_DisplayNthLongestFilm(int n, GenreCodes genre){
	std::vector<Movie*> listOfMovies;
	for (auto movie : _mdb_listOfMovies) {
		if (movie.second->m_getGenre().containsGenre(genre))
			listOfMovies.push_back(movie.second);
	}

	std::sort(listOfMovies.begin(), listOfMovies.end(), [&listOfMovies](Movie* m1, Movie* m2) {return m1->m_getRunTime() > m2->m_getRunTime(); });

	std::cout << *listOfMovies[n-1] << std::endl;
}

void MovieDatabase::mdb_DisplayNthRatedFilm(int n, GenreCodes genre) {
	std::vector<Movie*> listOfMovies;
	for (auto movie : _mdb_listOfMovies) {
		if (movie.second->m_getGenre().containsGenre(genre))
			listOfMovies.push_back(movie.second);
	}

	std::sort(listOfMovies.begin(), listOfMovies.end(), [&listOfMovies](Movie* m1, Movie* m2) {return m1->m_getMeanRating() > m2->m_getMeanRating(); });

	std::cout << *listOfMovies[n - 1] << std::endl;
}

void MovieDatabase::readFromFile(const std::string fileName){
	//Load the file into fstream
	std::ifstream file(fileName);

	//Check if file opened 
	if (!file.is_open())
		std::cerr << "File: " << fileName << " could not be opened!\n";
	

	//Read file until eof is reached
	while (!file.eof()){
		//Pass the file input into the database
		file >> *this;
	}

	std::cout << "All movies have been loaded from the file: " << fileName << " into the database" << std::endl;

	//Close the file after we are finished reading from it
	file.close();

}


