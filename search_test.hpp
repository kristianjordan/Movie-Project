#include "gtest/gtest.h"
#include "search.hpp"
#include <sstream>

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


