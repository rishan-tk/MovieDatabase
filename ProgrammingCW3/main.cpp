#include <iostream>
#include <fstream>

#include "MovieDatabase.h"
#include "RatingDatabase.h"

int main(int argc, char** argv) {
	
	MovieDatabase mdb;

	mdb.mdb_initialise("movies.txt");

	RatingDatabase rdb;

	rdb.rdb_initialise("ratings.txt", &mdb);

	std::cout << "\nTask #1 - Sort the Movies into chronological order of release year: " << std::endl;
	mdb.mdb_sortbyYear();

	std::cout << "\nTask #2 - Display the third longest Film-Noir : " << std::endl;
	mdb.mdb_DisplayNthLongestFilm(3, FILMNOIR);

	std::cout << "\nTask #3 - Display the 10th highest rated Scifi Movie: " << std::endl;
	mdb.mdb_DisplayNthRatedFilm(10, SCIFI);

	

	//std::cout << mdb << std::endl;

	//std::cout << rdb << std::endl;

	

	system("PAUSE");
	return 0;
}