#pragma once

#include "Rating.h"
#include "MovieDatabase.h"

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


	std::vector<Rating*> _rdb_listOfRatings;

};

//Inline Overloaded Operator functions
inline std::istream& operator>>(std::istream& input, RatingDatabase& rdb) {
	Rating tempRating;
	//Loop through each line in the file
	while (input >> tempRating)
		rdb._rdb_listOfRatings.emplace_back(new Rating(tempRating));
	
	return input;
}

inline std::ostream& operator<<(std::ostream& output, const RatingDatabase& rdb) {
	for (int i = 0; i < (int)rdb._rdb_listOfRatings.size(); i++)
		output << *rdb._rdb_listOfRatings[i];

	return output;
}