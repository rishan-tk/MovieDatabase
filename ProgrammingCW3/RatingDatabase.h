#pragma once

#include "Ratings.h"
#include "MovieDatabase.h"

/*****************************************
*				Legend                   *
*________________________________________*
*                                        *
* rdb_ = belongs to rating database class*
* _ before variables = private variable  *
*                                        *
*****************************************/

class RatingDatabase
{
public:
	RatingDatabase();
	~RatingDatabase();

	void rdb_initialise(const std::string fileName, MovieDatabase* mdb);

	friend std::istream& operator>>(std::istream& input, RatingDatabase& rdb);
	friend std::ostream& operator<<(std::ostream& output, const RatingDatabase& rdb);

private:
	void rdb_readFromFile(const std::string fileName, MovieDatabase* mdb);
	void rdb_updateRatings(MovieDatabase* mdb);


	std::vector<Ratings*> _rdb_listOfRatings;

};

//Inline Overloaded Operator functions
inline std::istream& operator>>(std::istream& input, RatingDatabase& rdb) {
	Ratings tempRating;
	//Loop through each line in the file
	while (input >> tempRating)
		rdb._rdb_listOfRatings.emplace_back(new Ratings(tempRating));
	
	return input;
}

inline std::ostream& operator<<(std::ostream& output, const RatingDatabase& rdb) {
	for (int i = 0; i < (int)rdb._rdb_listOfRatings.size(); i++)
		output << *rdb._rdb_listOfRatings[i];

	return output;
}