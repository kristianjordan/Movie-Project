#ifndef __SEARCH_HPP
#define __SEARCH_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Movie.h"

class SearchStrategy {
public:
 virtual vector<Movie*> search(vector<Movie*>, string) = 0;
};

//if 
class Search: public SearchStrategy{
	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s){
	for(int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 1
		}

		else
		{
		return 0; // return 0 if it didn't found the specific string in the vector 1
		}
  }
}
};

class SearchGenre: public Search {

	public:
	virtual vector<Movie*> Search(vector<Movie*> m, string s);
	for(int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 2
		}
	
	
	}
		return 0; // return 0 if it didn't found the specific string in the vector 1

};

class SearchTitle: public Search {

	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s){
	for(int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 3
		}
		else
		{
		return 0; // return 0 if it didn't found the specific string in the vector 1
		}
 }
}
};

class SearchRating: public Search {

	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s){
	for(int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 4 
		}
		else
		{
		return 0; // return 0 if it didn't found the specific string in the vector 1
		}
 }
}
};
#endif

