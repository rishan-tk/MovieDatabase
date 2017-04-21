#include <fstream>
#include <iostream>

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
		mdb_readFromFile(fileName);
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

void MovieDatabase::mdb_readFromFile(const std::string fileName){
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


