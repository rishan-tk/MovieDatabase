#pragma once

#include <iostream>
#include <iomanip>
#include <regex>

#include "Genre.h"

/*****************************************
*				Legend                   *
*________________________________________*
*                                        *
*   m_ = belongs to movie class          *
* _ before variables = private variable  *
*                                        *
*****************************************/

//Stores the information about a movie
class Movie
{
public:

	Movie();

	Movie(const Movie& movie);

	~Movie();

	void m_incrementNoOfRatings();
	void m_calculateMeanRatings();
	void m_updateMeanRatings(std::uint16_t meanRating);

	friend std::istream& operator>>(std::istream& input, Movie& m);
	friend std::ostream& operator<<(std::ostream& output, const Movie& m);

	friend bool operator>(const Movie& m1, const Movie&m2);
	friend bool operator>=(const Movie& m1, const Movie&m2);

	friend bool operator<(const Movie& m1, const Movie&m2);
	friend bool operator<=(const Movie& m1, const Movie&m2);

	friend bool operator==(const Movie& m1, const Movie&m2);
	friend bool operator!=(const Movie& m1, const Movie&m2);

	//Inline Accessor functions prototypes
	std::string m_getTitle() const;
	std::string m_getAgeRating() const;
	Genre m_getGenre() const;
	float m_getMeanRating() const;
	std::uint16_t m_getReleaseYear() const;
	std::uint16_t m_getRunTime() const;
	std::uint16_t m_getNoOfRatings() const;

private:
	std::string _m_title;
	std::string _m_ageRating;
	Genre _m_genre;
	float _m_meanRating;
	std::uint16_t _m_releaseYear;
	std::uint16_t _m_runTime;
	std::uint16_t _m_noOfRatings;

};

//Inline Accessor functions (variables not to be modified)
inline std::string Movie::m_getTitle() const { return _m_title; }
inline std::string Movie::m_getAgeRating() const { return _m_ageRating; }
inline Genre Movie::m_getGenre() const { return _m_genre; }
inline float Movie::m_getMeanRating() const { return _m_meanRating; }
inline std::uint16_t Movie::m_getReleaseYear() const { return _m_releaseYear; }
inline std::uint16_t Movie::m_getRunTime() const { return _m_runTime; }
inline std::uint16_t Movie::m_getNoOfRatings() const { return _m_noOfRatings; }

//Inline Overloaded Operator functions
inline std::istream& operator>>(std::istream& input, Movie& m) {
	//Temporary string to hold current line
	std::string tempString;
	std::smatch tempStringArray;

	//Store the line from input into tempString
	std::getline(input, tempString);

	//Check if string is empty
	if (tempString.empty())
		return input;

	//Perform regex on tempString to sort data
	std::regex delimiter("\"(.+?)\",([[:d:]]{4}),\"(.+?)\",\"(.+?)\",([[:d:]]{2,3}),([[:d:]]{1}),([[:d:]]{1})");
	
	//Perform regex search operation on tempString and store substrings into tempStringArray
	bool found = std::regex_match(tempString, tempStringArray, delimiter);

	//If file doesn't match the regular expression then return
	if (!found) {
		std::cout << "Entry doesn't follow the correct format!" << std::endl;
		return input;
	}

	//Store the information into movie
	m._m_title = tempStringArray[1];
	m._m_releaseYear = (std::uint16_t)std::stoi(tempStringArray[2]);
	m._m_ageRating = tempStringArray[3];
	m._m_genre.updateGenreFlags(tempStringArray[4]);
	m._m_runTime = (std::uint16_t)std::stoi(tempStringArray[5]);
	m._m_meanRating = (float)std::stoi(tempStringArray[6]);
	m._m_noOfRatings = (std::uint16_t)std::stoi(tempStringArray[7]);

	return input;
}

inline std::ostream& operator<<(std::ostream& output, const Movie& m) {
	output << "\"" << m._m_title << "\",";
	output << m._m_releaseYear << ",\"";
	output << m._m_ageRating << "\",\"";
	output << m._m_genre.toString() << "\",";
	output << m._m_runTime << ",";
	output << std::setprecision(3) << m._m_meanRating << ",";
	output << m._m_noOfRatings << std::endl;

	return output;
}


inline void Movie::m_incrementNoOfRatings() {
	_m_noOfRatings++;
}

inline void Movie::m_updateMeanRatings(std::uint16_t meanRating) {
	_m_meanRating += (float)meanRating;
}

inline void Movie::m_calculateMeanRatings() {
	_m_meanRating /= _m_noOfRatings;
}

inline bool operator>(const Movie& m1, const Movie&m2) {
	
	if(m1._m_releaseYear > m2._m_releaseYear)
		return true;
	else if (m1._m_releaseYear == m2._m_releaseYear) {
		for (int i = 0; i < (int)m1._m_title.size() && i < (int)m2._m_title.size(); i++)
			return m1._m_title[i] > m2._m_title[i];
	}else
		return false;

}

inline bool operator>=(const Movie& m1, const Movie&m2) {

	if (m1._m_releaseYear >= m2._m_releaseYear)
		return true;
	else if (m1._m_releaseYear == m2._m_releaseYear) {
		for (int i = 0; i < (int)m1._m_title.size() && i < (int)m2._m_title.size(); i++)
			return m1._m_title[i] >= m2._m_title[i];
	}else
		return false;
}

inline bool operator<(const Movie& m1, const Movie&m2) {

	if (m1._m_releaseYear < m2._m_releaseYear)
		return true;
	else if (m1._m_releaseYear == m2._m_releaseYear) {
		for (int i = 0; i < (int)m1._m_title.size() && i < (int)m2._m_title.size(); i++)
			return m1._m_title[i] < m2._m_title[i];
	}else
		return false;
}

inline bool operator<=(const Movie& m1, const Movie&m2) {

	if (m1._m_releaseYear <= m2._m_releaseYear)
		return true;
	else if (m1._m_releaseYear == m2._m_releaseYear) {
		for (int i = 0; i < (int)m1._m_title.size() && i < (int)m2._m_title.size(); i++)
			return m1._m_title[i] <= m2._m_title[i];
	}else
		return false;
}

inline bool operator==(const Movie & m1, const Movie & m2){
	return m1.m_getReleaseYear() == m2.m_getReleaseYear();
}

inline bool operator!=(const Movie & m1, const Movie & m2) {
	return m1.m_getReleaseYear() != m2.m_getReleaseYear();
}
