#include <iostream>
#include "Movie.h"
#include "MovieContext.h"

using namespace std;

int main() {
    MovieContext * movie = MovieContext::getInstance();
    movie->getMovie();
    movie->printMovies();
    return 0;
}

