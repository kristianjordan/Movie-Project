#ifndef _SEARCH_HPP
#define _SEARCH_HPP
#include "Movie.h"
#include <vector>
#include <string>
#include <cstring>
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
        vector<Movie*> genreMovieHolder;
        for (Movie* movie : m)
        {
            string rating = movie->get_rating();
            string searchStr = s;
            upper_string(rating);
            upper_string(searchStr);
            if (rating.find(searchStr) != std::string::npos)
            {
                genreMovieHolder.push_back(movie);
            }
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
        vector<Movie*> titleMovieHolder;
        for (Movie* movie : m)
        {
            string title = movie->get_title();
            string searchStr = s;
            upper_string(title);
            upper_string(searchStr);
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
            if (strcasecmp(rating.c_str(), searchStr.c_str()))
            {
                ratingMovieHolder.push_back(movie);
            }
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

