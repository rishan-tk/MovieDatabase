#include <iostream>
#include <fstream>

#include "MovieDatabase.h"
#include "RatingDatabase.h"

int main(int argc, char** argv) {
	
	MovieDatabase mdb;

	mdb.mdb_initialise("movies.txt");

	RatingDatabase rdb;

	rdb.rdb_initialise("ratings.txt", &mdb);

	std::cout << mdb << std::endl;

	std::cout << rdb << std::endl;

	

	system("PAUSE");
	return 0;
}