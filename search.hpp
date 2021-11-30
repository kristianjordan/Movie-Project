#ifndef _SEARCH_HPP
#define _SEARCH_HPP
#include "Movie.h"
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

/*
 * ***********************************************************************************
 * SearchStrategy abstract class that search strategies will inherit from
 * NOT yet complete, waiting on partners to implement this code
 * ************************************************************************************
 */
class SearchStrategy
{
protected:
    void upper_string(std::string& str) const
    {
        for (int i=0; i<str.length(); i++)
            str[i] = toupper(str[i]);
    }
public:
    virtual vector<Movie*> search(vector<Movie*>, string) = 0;
};

class SearchGenre : public SearchStrategy
{
public:
	SearchGenre(){}
	vector<Movie*> search(vector<Movie*> m, string s)
 { 
	vector<Movie*> genreMovieHolder; //making new vector so that original vector<Movie*> data is not manipulated
	for(Movie* movie : m)//looping through the vector
	{	
		//
 		string genre = movie->get_genre();
		string searchStr = s;
		upper_string(genre);
		upper_string(searchStr);
		
		//if search criteria matches any part of the genre
	if (strcasecmp(genre.c_str(), searchStr.c_str()) == 0)
            {
                genreMovieHolder.push_back(movie);
            }
		else s.compare(movie->get_genre());
        }
        return genreMovieHolder;

    }
};

class SearchTitle : public SearchStrategy
{
public:
	SearchTitle(){}
	vector<Movie*> search(vector<Movie*> m, string s)
 { 
	vector<Movie*> titleMovieHolder; //making new vector so that original vector<Movie*> data is not manipulated
	for(Movie* movie : m)//looping through the vector
	{	
		//
 		string title = movie->get_title();
		string searchStr = s;
		upper_string(title);
		upper_string(searchStr);
		
		//if search criteria matches any part of the genre
	 if (title.find(searchStr) != std::string::npos)
            {
                titleMovieHolder.push_back(movie);
            }
        }
        return titleMovieHolder;
    }
};

class SearchRating : public SearchStrategy
{
public:
    SearchRating(){}
    vector<Movie*> search(vector<Movie*> m, string s)
    {
        vector<Movie*> ratingMovieHolder;
        for (Movie* movie : m)
        {
            string rating = movie->get_rating();
            string searchStr = s;
            upper_string(rating);
            upper_string(searchStr);
            if (strcasecmp(rating.c_str(), searchStr.c_str()) == 0)
            {
                ratingMovieHolder.push_back(movie);
            }
		else s.compare(movie->get_rating());
        }
       return ratingMovieHolder; 
    }
};

class SearchMood : public SearchStrategy {
public:
    SearchMood() {}
    vector<Movie *> search(vector<Movie *> m, string s) {
        vector<Movie *> result;
        vector<string> genreMatch;
        // mood is happy
        if (strcasecmp(s.c_str(), "happy") == 0) {
            genreMatch.push_back("COMEDY");
            genreMatch.push_back("ADVENTURE");
        }
            // mood is sad
        else if (strcasecmp(s.c_str(), "sad") == 0) {
            genreMatch.push_back("DRAMA");
            genreMatch.push_back("THRILLER");
        } else if (strcasecmp(s.c_str(), "neutral") == 0) { // mood is neutral
            genreMatch.push_back("COMEDY");
            genreMatch.push_back("ACTION");
            genreMatch.push_back("ROMANCE");
        }
        for (Movie *movie : m) {
            string genres = movie->get_genre();
            upper_string(genres);
            for (string match : genreMatch)
                if (genres.find(match) != std::string::npos) {
                    result.push_back(movie);
                    break;
                }
        }
        return result;
    }
};

#endif //_SEARCH_HPP
