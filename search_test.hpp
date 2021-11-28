#ifndef __SEARCH_TEST_HPP
#define __SEARCH_TEST_HPP
#include "gtest/gtest.h"

#include "search.hpp"
#include "Movie.h"
#include "MovieContext.h"
#include <sstream>
#include <string>
#include <vector>

TEST(TestingSearchGenre, emptyString){
std::vector<Movie*>m;
SearchStrategy* s = new SearchGenre();
EXPECT_TRUE((s->search(m).empty()));
}

TEST(TestingSearchGenre, inputNotFound){
std::vectr<Movie*>m;
SearchStrategy* s = new SearchGenre();
movie* Movie = new movie();
EXPECT_EQ("", s());
}

#endif
