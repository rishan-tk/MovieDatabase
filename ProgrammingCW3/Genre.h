#pragma once

#include <cstdint>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <istream>

/*****************************
*   For bitmasking genres    *
* Genre    (bit) (hex value) *
* Action      1   =     0x1  *
* Adventure   2   =     0x2  *   
* Animation   3   =     0x4  *
* Biography   4   =     0x8  *
* Comedy      5   =    0x10  *
* Crime       6   =    0x20  *
* Drama       7   =    0x40  * 
* Family      8   =    0x80  *
* Fantasy     9   =   0x100  *
* Film-Noir  10   =   0x200  *                                                                         
* History    11   =   0x400  *
* Horror     12   =   0x800  *
* Music      13   =  0x1000  *                                      
* Musical    14   =  0x2000  *
* Mystery    15   =  0x4000  *       
* Romance    16   =  0x8000  *                                                         
* Sci-Fi     17   =  0x10000 *                                                                       
* Thriller   18   =  0x20000 *                                                                                   
* War        19   =  0x40000 *
* Western	 20   =  0x80000 *
*****************************/

typedef enum GenreCodes {
	ACTION = 0x1,
	ADVENTURE = 0x2,
	ANIMATION = 0x4,
	BIOGRAPHY = 0x8,
	COMEDY = 0x10,
	CRIME = 0x20,
	DRAMA = 0x40,
	FAMILY = 0x80,
	FANTASY = 0x100,
	FILMNOIR = 0x200,
	HISTORY = 0x400,
	HORROR = 0x800,
	MUSIC = 0x1000,
	MUSICAL = 0x2000,
	MYSTERY = 0x4000,
	ROMANCE = 0x8000,
	SCIFI = 0x10000,
	THRILLER = 0x20000,
	WAR = 0x40000,
	WESTERN = 0x80000
}genre_codes;

struct Genre
{
public:
	//Store the flags for each genre in this variable
	std::uint32_t genres;

	//Convert the genres in the string into flags which are set in genres
	void updateGenreFlags(std::string genre) {
		//To hold the strings to be extracted from genre 
		std::vector<std::string> tempStrings;
		std::string tempString;
		genres = 0;

		//Turn the string into a stream
		std::stringstream ss(genre);

		char delimiter = '/';

		//Extract all genres into tempStrings
		while (std::getline(ss, tempString, delimiter))
			tempStrings.push_back(tempString);
		

		//Add the flags for the genres extracted
		for (std::string s : tempStrings) {
			switch (hashString(s)) {
				case ACTION: 
					genres |= ACTION;
					break;
				case ADVENTURE: 
					genres |= ADVENTURE;
					break;
				case ANIMATION:
					genres |= ANIMATION;
					break;
				case BIOGRAPHY:
					genres |= BIOGRAPHY;
					break;
				case COMEDY:
					genres |= COMEDY;
					break;
				case CRIME:
					genres |= CRIME;
					break;
				case DRAMA:
					genres |= DRAMA;
					break;
				case FAMILY:
					genres |= FAMILY;
					break;
				case FANTASY:
					genres |= FANTASY;
					break;
				case FILMNOIR:
					genres |= FILMNOIR;
					break;
				case HISTORY:
					genres |= HISTORY;
					break;
				case HORROR:
					genres |= HORROR;
					break;
				case MUSIC:
					genres |= MUSIC;
					break;
				case MUSICAL:
					genres |= MUSICAL;
					break;
				case MYSTERY:
					genres |= MYSTERY;
					break;
				case ROMANCE:
					genres |= ROMANCE;
					break;
				case SCIFI:
					genres |= SCIFI;
					break;
				case THRILLER:
					genres |= THRILLER;
					break;
				case WAR:
					genres |= WAR;
					break;
				case WESTERN:
					genres |= WESTERN;
					break;
			}
		}	
		 
	}

	bool containsGenre(GenreCodes mask) const {
		return genres & mask;
	}

	std::string toString() const {
		std::string tempString = "";
		int mask = 0x1;

		//Go through all the bits containing flags
		for (int i = 0; i < 19; i++) {
			switch (genres & mask) {
				case ACTION:
					tempString += "Action/";
					break;
				case ADVENTURE:
					tempString += "Adventure/";
					break;
				case ANIMATION:
					tempString += "Animation/";
					break;
				case BIOGRAPHY:
					tempString += "Biography/";
					break;
				case COMEDY:
					tempString += "Comedy/";
					break;
				case CRIME:
					tempString += "Crime/";
					break;
				case DRAMA:
					tempString += "Drama/";
					break;
				case FAMILY:
					tempString += "Family/";
					break;
				case FANTASY:
					tempString += "Fantasy/";
					break;
				case FILMNOIR:
					tempString += "Film-Noir/";
					break;
				case HISTORY:
					tempString += "History/";
					break;
				case HORROR:
					tempString += "Horror/";
					break;
				case MUSIC:
					tempString += "Music/";
					break;
				case MUSICAL:
					tempString += "Musical/";
					break;
				case MYSTERY:
					tempString += "Mystery/";
					break;
				case ROMANCE:
					tempString += "Romance/";
					break;
				case SCIFI:
					tempString += "Sci-Fi/";
					break;
				case THRILLER:
					tempString += "Thriller/";
					break;
				case WAR:
					tempString += "War/";
					break;
				case WESTERN:
					tempString += "Western/";
					break;
				default:
					break;
			}
			//Check the next bit
			mask <<= 1;
		}

		return tempString.substr(0, (int)tempString.size()-1);
	}


private:
	genre_codes hashString(const std::string& genreTitle) {
		if (genreTitle == "Action")
			return ACTION;
		else if (genreTitle == "Adventure")
			return ADVENTURE;
		else if (genreTitle == "Animation")
			return ANIMATION;
		else if (genreTitle == "Biography")
			return BIOGRAPHY;
		else if (genreTitle == "Comedy")
			return COMEDY;
		else if (genreTitle == "Crime")
			return CRIME;
		else if (genreTitle == "Drama")
			return DRAMA;
		else if (genreTitle == "Family")
			return FAMILY;
		else if (genreTitle == "Fantasy")
			return FANTASY;
		else if (genreTitle == "Film-Noir")
			return FILMNOIR;
		else if (genreTitle == "History")
			return HISTORY;
		else if (genreTitle == "Horror")
			return HORROR;
		else if (genreTitle == "Music")
			return MUSIC;
		else if (genreTitle == "Musical")
			return MUSICAL;
		else if (genreTitle == "Mystery")
			return MYSTERY;
		else if (genreTitle == "Romance")
			return ROMANCE;
		else if (genreTitle == "Sci-Fi")
			return SCIFI;
		else if (genreTitle == "Thriller")
			return THRILLER;
		else if (genreTitle == "War")
			return WAR;
		else if (genreTitle == "Western")
			return WESTERN;
	}

};



