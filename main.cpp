#include <iostream>
#include "Movie.h"
#include "MovieContext.h"

using namespace std;

int main() {
    MovieContext * movie = MovieContext::getInstance();
    vector<Movie*> movieList = movie->getMovie();
    movie->printMovies(movieList);
    return 0;
}

