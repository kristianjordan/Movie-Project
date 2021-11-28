#ifndef __SEARCH_HPP
#define __SEARCH_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
class SearchStrategy {
public:
 virtual vector<Movie*> search(vector<Movie*>, string) = 0;
};

//if 
class search:: public SearchStrategy{
	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s)
	for( int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 
		}
	}
	return 0; // return 0 if it didn't found the specific string in the vector
}

class SearchGenre:: public search {

	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s)
	for( int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 
		}
	}
	return 0; // return 0 if it didn't found the specific string in the vector

}

class SearchTitle:: public search {

	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s)
	for( int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 
		}
	}
	return 0; // return 0 if it didn't found the specific string in the vector

}

class SearchRating:: public search {

	public:
	virtual vector<Movie*> search(vector<Movie*> m, string s)
	for( int i = 0; i <  m.size(); i++){
 		string str = m[i];
		if (str == s)
		{
		  return s;//it will return the string being searched for if it exists 
		}
	}
	return 0; // return 0 if it didn't found the specific string in the vector

}
#endif

