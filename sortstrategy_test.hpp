#ifndef __SORT_STRATEGY_TEST_HPP
#define __SORT_STRATEGY_TEST_HPP

#include "mock_files/mock_movie.hpp"
#include "sortstrategy.hpp"

#include <cstdlib>
#include <ctime>

TEST(SortingRatings, EmptyVector)
{
	std::vector<Movie> v;
	SortStrategy* ss = new SortRatings;
	EXPECT_TRUE((ss->sort(v).empty()));
}
TEST(SortingRatings, RandomVector)
{
	std::vector<Movie> v;
	std::srand(std::time(nullptr));
	for(int i = 0; i < 10; ++i)
	{
		v.push_back(Movie(std::to_string((double)rand() / rand())));	
	}
	SortStrategy* ss = new SortRatings;
	std::vector<Movie> m = ss->sort(v);
	double sum = 0;
	for(int i = 0; i < m.size() - 1; ++i)
	{
		EXPECT_GE(std::stod(m.at(i).get_rating()), std::stod(m.at(i + 1).get_rating()));
	}
}
TEST(SortingRatings, RandomDuplicatesVector)
{
	std::vector<Movie> v;
	std::srand(std::time(nullptr));
	int count = 0;
	std::string s;
	for(int i = 0; i < 5; ++i)
	{
		std::string current = std::to_string((double)rand() / rand());
		if(count == 0)
		{
			s =	current;
		}
		if(count == 2)
		{
			v.push_back(Movie(current));	
			count = 0;
		}
		v.push_back(Movie(current));
		++count;
	}
	SortStrategy* ss = new SortRatings;
	std::vector<Movie> m = ss->sort(v);
	double sum = 0;
	for(int i = 0; i < m.size() - 1; ++i)
	{
		EXPECT_GE(std::stod(m.at(i).get_rating()), std::stod(m.at(i + 1).get_rating())); 
	}
}

#endif

		
