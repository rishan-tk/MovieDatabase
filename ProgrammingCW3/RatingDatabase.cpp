#include <fstream>

#include "RatingDatabase.h"

RatingDatabase::RatingDatabase()
{
}


RatingDatabase::~RatingDatabase(){
	for (int i = 0; i < (int)_rdb_listOfRatings.size(); i++)
		delete _rdb_listOfRatings[i];
}

void RatingDatabase::rdb_initialise(const std::string fileName, MovieDatabase* mdb){
	//Read from file
	rdb_readFromFile(fileName, mdb);
}

void RatingDatabase::rdb_readFromFile(const std::string fileName, MovieDatabase* mdb){
	//Load the file into fstream
	std::ifstream file(fileName);

	//Check if file opened 
	if (!file.is_open())
		std::cerr << "File: " << fileName << " could not be opened!\n";

	//Read file until eof is reached
	while (!file.eof()) {
		//Pass the file input into the database
		file >> *this;
	}

	rdb_updateRatings(mdb);



	std::cout << "All ratings have been loaded from the file: " << fileName << " into the database" << std::endl;

	//Close the file after we are finished reading from it
	file.close();
}

void RatingDatabase::rdb_updateRatings(MovieDatabase* mdb){
	for (int i = 0; i < (int)_rdb_listOfRatings.size(); i++)
		mdb->mdb_updateRatings(_rdb_listOfRatings[i]->r_getMovieTitle(), _rdb_listOfRatings[i]->r_getUserRating());

	mdb->mdb_calculateRatings();
}


