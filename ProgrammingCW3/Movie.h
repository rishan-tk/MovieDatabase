#pragma once

#include <string>
#include <cstdint>

//Use a bitfield for genre

/****************************************
*				Legend                  *
*_______________________________________*
*                                       *
*   m_ = belongs to movie class         *
* _ before variables = private variable *
*                                       *
****************************************/

//Store the information about a movie
class Movie
{
public:
	//If nothing is passed in for meanRating of noOfRatings, set them to 0
	Movie(std::string title, uint16_t releaseYear, std::string ageRating, std::string genre, uint16_t runTime, uint8_t meanRating = 0, uint16_t noOfRatings = 0);

	~Movie();

	void m_incrementNoOfRatings();

	//Inline Accessor functions prototypes
	std::string m_getTitle() const;
	std::string m_getAgeRating() const;
	std::string m_getGenre() const;
	std::uint8_t m_getMeanRating() const;
	std::uint16_t m_getReleaseYear() const;
	std::uint16_t m_getRunTime() const;
	std::uint16_t m_getNoOfRatings() const;

private:
	std::string _m_title;
	std::string _m_ageRating;
	std::string _m_genre;
	std::uint8_t _m_meanRating;
	std::uint16_t _m_releaseYear;
	std::uint16_t _m_runTime;
	std::uint16_t _m_noOfRatings;

};

//Inline Accessor functions (variables not to be modified)
inline std::string Movie::m_getTitle() const { return _m_title; }
inline std::string Movie::m_getAgeRating() const { return _m_ageRating; }
inline std::string Movie::m_getGenre() const { return _m_genre; }
inline std::uint8_t Movie::m_getMeanRating() const { return _m_meanRating; }
inline std::uint16_t Movie::m_getReleaseYear() const { return _m_releaseYear; }
inline std::uint16_t Movie::m_getRunTime() const { return _m_runTime; }
inline std::uint16_t Movie::m_getNoOfRatings() const { return _m_noOfRatings; }

