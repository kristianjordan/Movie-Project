#ifndef __SORT_STRATEGY_TEST_HPP
#define __SORT_STRATEGY_TEST_HPP

#include "Movie.h"
#include "sortstrategy.hpp"

#include <cstdlib>
#include <ctime>
																							
TEST(SortingRatings, EmptyVector)
{
	std::vector<Movie*> v;
	SortStrategy* ss = new SortRating;
	EXPECT_TRUE((ss->sort(v).empty()));
	delete ss;
}
TEST(SortingRatings, RandomVector)
{
	std::vector<Movie*> v;
	std::srand(std::time(nullptr));
	map<std::string, int> ratings = { {"Unrated", -1},{"TV-Y", 0},{"TV-Y7", 1},{"TV-FY FV", 2},{"G", 3},{"TV-G", 4},{"PG", 5},{"TV-PG", 6},{"PG-13", 7},{"TV-14", 8},{"R", 9},{"NC-17", 10},{"TV-MA", 11} };	
	vector<std::string> rate = {"Unrated", "TV-Y", "TV-Y7", "TV-PG", "PG-13", "NC-17", "TV-MA", "R", "G", "PG"};
	for(int i = 0; i < 10; ++i)
	{
		std::string current = rate.at(rand() % rate.size());
		Movie* m = new Movie;
		m->set_rating(current);
		v.push_back(m);
	}
	SortStrategy* ss = new SortRating;
	v = ss->sort(v);
	for(int i = 0; i < v.size() - 1; ++i)
	{
		EXPECT_GE(ratings[(v.at(i)->get_rating())], ratings[(v.at(i + 1)->get_rating())]);
	}
	delete ss;
	for(auto i : v)
	{
		delete i;
	}
}
TEST(SortingRatings, DuplicatesVector)
{
	std::vector<Movie*> v;
	std::srand(std::time(nullptr));
	map<std::string, int> ratings = { {"Unrated", -1},{"TV-Y", 0},{"TV-Y7", 1},{"TV-FY FV", 2},{"G", 3},{"TV-G", 4},{"PG", 5},{"TV-PG", 6},{"PG-13", 7},{"TV-14", 8},{"R", 9},{"NC-17", 10},{"TV-MA", 11} };	
	vector<std::string> rate = {"Unrated", "TV-Y", "TV-Y7", "TV-PG", "PG-13", "NC-17", "TV-MA", "R", "G", "PG"};
	for(int i = 0; i < 5; ++i)
	{
		std::string current = rate.at(rand() % rate.size());
		Movie* m = new Movie;
		Movie* duplicate = new Movie;
		m->set_rating(current);
		duplicate->set_rating(current);
		v.push_back(m);
		v.push_back(duplicate);
	}
	SortStrategy* ss = new SortRating;
	v = ss->sort(v);
	for(int i = 0; i < v.size() - 1; ++i)
	{
		EXPECT_GE(ratings[(v.at(i)->get_rating())], ratings[(v.at(i + 1)->get_rating())]); 
	}
	delete ss;
	for(auto i : v)
	{
		delete i;
	}
}

TEST(SortingDuration, EmptyVector)
{
	std::vector<Movie*> v;
	SortStrategy* ss = new SortDuration;
	EXPECT_TRUE((ss->sort(v).empty()));
	delete ss;
}
TEST(SortingDuration, RandomDurations)
{
	std::vector<Movie*> v;
	std::srand(std::time(nullptr));
	for(int i = 0; i < 10; ++i)
	{
		Movie* m = new Movie;
		m->set_duration((((double)rand() / rand()) * 15));
		v.push_back(m);	
	}
	SortStrategy* ss = new SortDuration;
	std::vector<Movie*> m = ss->sort(v);
	for(int i = 0; i < m.size() - 1; ++i)
	{
		EXPECT_GE(m.at(i)->get_duration(), m.at(i + 1)->get_duration());
	}
	delete ss;
	for(auto i : m)
	{
		delete i;
	}
	m.clear();
}
TEST(SortingDuration, RandomDuplicatesDurations)
{
	std::vector<Movie*> v;
	std::srand(std::time(nullptr));
	for(int i = 0; i < 5; ++i)
	{
		int current = (((double)rand() / rand()) * 15);
		Movie* m = new Movie;
		Movie* duplicate = new Movie;
		m->set_duration(current);
		duplicate->set_duration(current);
		v.push_back(m);
		v.push_back(duplicate);
	}
	SortStrategy* ss = new SortDuration;
	std::vector<Movie*> m = ss->sort(v);
	for(int i = 0; i < m.size() - 1; ++i)
	{
		EXPECT_GE(m.at(i)->get_duration(), m.at(i + 1)->get_duration()); 
	}
	delete ss;
	for(auto i : m)
	{
		delete i;
	}
	m.clear();
}

TEST(SortingByGenre, EmptyVector)
{
	std::vector<Movie*> v;
	SortStrategy* ss = new SortGenre;
	EXPECT_TRUE((ss->sort(v).empty()));
	delete ss;
}
TEST(SortingByGenre, Multiples)
{
	std::vector<Movie*> v;
	std::srand(std::time(nullptr));
	std::vector<std::string> str = {"Adventure", "Fantasy", "Futuristic", "BioTech", "Modern", "Doomed", "Nuclear", "Horror", "Basic", "LandMine", "Action", "Drama", "Comedy", "Thriller"};
	for(int i = 0; i < 10; ++i)
	{
		Movie* m = new Movie;
		m->set_genre(str.at(rand() % str.size()));
		v.push_back(m);
	}
	SortStrategy* ss = new SortGenre;
	std::vector<Movie*> m = ss->sort(v);
	double sum = 0;
	for(int i = 0; i < m.size() - 1; ++i)
	{
		EXPECT_LE(m.at(i)->get_genre().compare(m.at(i + 1)->get_genre()), 0);
	}
	delete ss;
	for(auto i : m)
	{
		delete i;
	}
	m.clear();
}
TEST(SortingByGenre, Duplicates)
{
	std::vector<Movie*> v;
	std::srand(std::time(nullptr));
	std::vector<std::string> str = {"Adventure", "Fantasy", "Futuristic", "BioTech", "Modern", "Doomed", "Nuclear", "Horror", "Basic", "LandMine", "Action", "Drama", "Comedy", "Thriller"};
	for(int i = 0; i < 5; ++i)
	{
		std::string current = str.at(rand() % str.size());
		Movie* m = new Movie;
		Movie* duplicate = new Movie;
		m->set_genre(current);
		duplicate->set_genre(current);
		v.push_back(m);
		v.push_back(duplicate);
	}
	SortStrategy* ss = new SortGenre;
	std::vector<Movie*> m = ss->sort(v);
	for(int i = 0; i < m.size() - 1; ++i)
	{
		EXPECT_LE(m.at(i)->get_genre().compare(m.at(i + 1)->get_genre()), 0);
	}
	delete ss;
	for(auto i : m)
	{
		delete i;
	}
	m.clear();
}

#endif		
