#ifndef __SEARCH_TEST_HPP_
#define __SEARCH_TEST_HPP_
#include "gtest/gtest.h"

#include "search.hpp"
#include "Movie.h"
#include <sstream>
#include <string>
#include <vector>

TEST(TestingSearchGenre, empty){
std::vector<Movie*> g;
std::string ss;
SearchStrategy* s = new SearchGenre;
EXPECT_TRUE((s->search(g, ss).empty()));
delete s;//deallocation
}

TEST(TestingSearchGenre, genreAction){
std::vector<Movie*> g;
std::string ss;
Movie* movie = new Movie();
movie->set_genre("Action");
SearchStrategy* s = new SearchGenre;
EXPECT_TRUE((s->search(g,ss), movie));
delete s;//deallocation
delete movie;//deallocation
}
/*
TEST(TestingSearchGenre, inputNotFound){
std::vectr<Movie*>m;
SearchStrategy* s = new SearchGenre();
movie* Movie = new movie();
EXPECT_EQ("", s());
};
*/

#endif
