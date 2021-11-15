#ifndef __MOCK_MOVIE_HPP
#define __MOCK_MOVIE_HPP

#include <string>

class Movie
{
	private:
		std::string rating;
	public:
		Movie(std::string r) : rating{r} {};
		std::string get_rating() { return rating; };
};

#endif
