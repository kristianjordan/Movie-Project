#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Movie.h"

//abstract class that other searches will inherit from
class SearchStrategy {
//using this function will help with case sensitivity when doing comparisons
protected:
	void upper_string(std::string& str)
	{
	 for (int i = 0; i<str.length();i++)
	  str[i] = toupper(str[i]);
	}

public:
 virtual vector<Movie*> search(vector<Movie*>, string) = 0;
};


//Search by genre which inherits from SearchStrategy
class SearchGenre: public SearchStrategy {

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
		 if (rating.find(searchStr) != std::string::npos)
            {
                genreMovieHolder.push_back(movie);
            }
        }
// return the genreMovieHolder 
//genreMovieHolder will contain a vector of pointers to movie objects which all contain the search criteria)
       return genreMovieHolder;
 } 	            
};

//Search by title which inherits from SearchStrategy
class SearchTitle: public SearchStrategy {

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
		 if (rating.find(searchStr) != std::string::npos)
            {
                titleMovieHolder.push_back(movie);
            }
        }
// return the titleMovieHolder 
//titleMovieHolder will contain a vector of pointers to movie objects which all contain the search criteria)
       return titleMovieHolder;
 } 	            
};

//Search by rating which inherits from SearchStrategy
class SearchRating: public SearchStrategy {

public:
	SearchRating(){}
	vector<Movie*> search(vector<Movie*> m, string s)
 { 
	vector<Movie*> ratingMovieHolder; //making new vector so that original vector<Movie*> data is not manipulated
	for(Movie* movie : m)//looping through the vector
	{	
		//
 		string rating = movie->get_rating();
		string searchStr = s;
		upper_string(rating);
		upper_string(searchStr);
		
		//if search criteria matches any part of the genre
		 if (rating.find(searchStr) != std::string::npos)
            {
                ratingMovieHolder.push_back(movie);
            }
        }
// return the ratingMovieHolder 
//ratingMovieHolder will contain a vector of pointers to movie objects which all contain the search criteria)
       return ratingMovieHolder;
 } 	            
};

#endif
