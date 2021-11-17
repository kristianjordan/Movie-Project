#ifndef __MOVIESINGLETON_TEST_HPP__
#define __MOVIESINGLETON_TEST_HPP__
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "Movie.h"
#include "MovieContext.h"
using namespace std;

TEST(MovieTest, MovieDataTest) {
	// create movie object
	Movie* movie = new Movie();
	movie->set_title("Avatar");
	movie->set_rating("PG-13");
	movie->set_directorName("James Cameron");
	movie->set_actorName("Joel David Moore, CCH Pounder, Wes Studi");
	movie->set_duration(178);	

	EXPECT_EQ(movie->get_title(), "Avatar"); 
	EXPECT_EQ(movie->get_rating(), "PG-13");
	EXPECT_EQ(movie->get_directorName(), "James Cameron");
	EXPECT_EQ(movie->get_actorName(), "Joel David Moore, CCH Pounder, Wes Studi");
	EXPECT_EQ(movie->get_duration(), 178);

	// deallocation
	delete movie;
}

TEST(MovieContext, GetInstanceTest) {
	MovieContext* instance = MovieContext::getInstance();
	SearchStrategy* search = new SearchTitle();
	instance->setSearchStrategy(search); // setting the strategy inside MovieContext object 
	
	MovieContext* newInstance = MovieContext::getInstance();

	EXPECT_EQ(instance->getSearchStrategy(), newInstance->getSearchStrategy());
}


TEST(MovieContext, SearchStrategyTest) {
	MovieContext* movie = MovieContext::getInstance();
	SearchStrategy* search = new SearchGenre();
	movie->setSearchStrategy(search);
	SearchStrategy* searchHolder = movie->getSearchStrategy();

	EXPECT_EQ(searchHolder, search);
}


TEST(MovieContext, SortStrategyTest) {
        MovieContext* movie = MovieContext::getInstance();
        SortStrategy* sort = new SortGenre();
        movie->setSortStrategy(sort);
        SortStrategy* sortHolder = movie->getSortStrategy();

        EXPECT_EQ(sortHolder, sort);	
}

TEST(MovieContext, GetMovieTest) {
        MovieContext* movie = MovieContext::getInstance();
        vector<Movie*> movieListings;
	movieListings = movie->getMovie();

	string title_results;
	title_results = movieListings[0]->get_title();
	
	string rating_results;
	rating_results = movieListings[1]->get_rating();

	string directorName_results;
	directorName_results = movieListings[2]->get_directorName();

	string actorName_results;
        actorName_results = movieListings[3]->get_actorName();
	
	string duration_results;
        duration_results = movieListings[4]->get_duration();


        EXPECT_EQ(title_results, "Avatar");
	EXPECT_EQ(rating_results, "PG-13");
	EXPECT_EQ(directorName_results, "Sam Mendes");
	EXPECT_EQ(actorName_results, "Christian Bale, Tom Hardy, Joseph Gordon-Levitt");
	EXPECT_EQ(duration_results, "");

	movie->freeInstance();
}

#endif //__MOVIESINGLETON_TEST_HPP__

