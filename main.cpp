#include <iostream>
#include <iomanip>
#include "Movie.h"
#include "MovieContext.h"

using namespace std;

void displaySearchMenu()
{
    cout << endl << "Enter how you would like to search (#1-3): " << endl;
    cout << "1. Search by Title." << endl;
    cout << "2. Search by Genre." << endl;
    cout << "3. Search by Rating (G, PG, PG-13, R, NC-17)." << endl << endl;
}

void displaySortMenu()
{
    cout << endl << "Enter how you would like to sort (#1-3):" << endl;
    cout << "1. Sort by Genre." << endl;
    cout << "2. Sort by Duration." << endl;
    cout << "3. Sort by Rating (G, PG, PG-13, R, NC-17)." << endl << endl;
}
int main() {
    // creating instance of MovieContext
    MovieContext * movie = MovieContext::getInstance();


    cout << endl << endl << setw(40) << "Moodvie Recommender" << endl;
    cout << setw(52) << "By: Kristian Jordan, Selena Aria, Gary Zeng" << endl << endl;
    /*
     * Display menu for searching, and take in user input
    */
    char search;
    bool again = false;
    vector<Movie*> searchResults;
    vector<Movie*> sortResults;
    do
    {
        displaySearchMenu();
        cin >> search;
        if ((search < '1') || (search > '3'))
        {
            again = true;
            cout << "Invalid input. Try again." << endl;
        }

        else if (search == '1')
        {
            SearchStrategy * searchList = new SearchTitle(); // create pointer to SearchRating strategy
            movie->setSearchStrategy(searchList); // set strategy in MovieContext to SearchRating
            SearchStrategy* search = movie->getSearchStrategy(); // create another SearchStrategy pointer
            // and assign to SearchRating
            // using MovieContext getSearchStrategy function
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers
            // and assign it to the vector
            // ask user to enter title of movie
            string movieTitle;
            cout << "Enter the title of the Movie: ";
            cin >> movieTitle;
            // that holds the repo of movies
            searchResults = search->search(movieList, movieTitle); // create new vector to hold
                                                                                // the vector of Movies
            again = false;
        }
        else if (search == '2')
        {
            SearchStrategy * searchList = new SearchGenre(); // create pointer to SearchRating strategy
            movie->setSearchStrategy(searchList); // set strategy in MovieContext to SearchRating
            SearchStrategy* search = movie->getSearchStrategy(); // create another SearchStrategy pointer
            // and assign to SearchRating
            // using MovieContext getSearchStrategy function
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers
            // and assign it to the vector
            // ask user to enter title of movie
            string movieGenre;
            cout << "Enter the genre of the Movie: ";
            cin >> movieGenre;
            // that holds the repo of movies
            searchResults = search->search(movieList, movieGenre); // create new vector to hold
            // the vector of Movies
            again = false;
        }
        else if (search == '3')
        {
            SearchStrategy * searchList = new SearchRating(); // create pointer to SearchRating strategy
            movie->setSearchStrategy(searchList); // set strategy in MovieContext to SearchRating
            SearchStrategy* search = movie->getSearchStrategy(); // create another SearchStrategy pointer
            // and assign to SearchRating
            // using MovieContext getSearchStrategy function
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers
            // and assign it to the vector
            // ask user to enter title of movie
            string movieRating;
            cout << "Enter the rating of the Movie: ";
            cin >> movieRating;
            // that holds the repo of movies
            searchResults = search->search(movieList, movieRating); // create new vector to hold
            // the vector of Movies
            again = false;
        }
    } while(again);

    /*
     * Display sorting menu, read in input from user
    */
    char sort;
    do
    {
        displaySortMenu();
        cin >> sort;
        if ((sort < '1') || (sort > '3'))
        {
            again = true;
            cout << "Invalid input. Try again." << endl;
        }
        if (sort == '1')
        {
            SortStrategy * sortList = new SortGenre();
            movie->setSortStrategy(sortList);
            SortStrategy * sortHolder = movie->getSortStrategy();
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers and assign it to the vector
            // that holds the repo of movies
            sortResults = sortHolder->sort(searchResults);
            again = false;
        }
        else if (sort == '2')
        {
            SortStrategy * sortList = new SortDuration();
            movie->setSortStrategy(sortList);
            SortStrategy * sortHolder = movie->getSortStrategy();
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers and assign it to the vector
            // that holds the repo of movies
            sortResults = sortHolder->sort(searchResults);
            again = false;
        }
        else if (sort == '3')
        {
            SortStrategy * sortList = new SortRating();
            movie->setSortStrategy(sortList);
            SortStrategy * sortHolder = movie->getSortStrategy();
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers and assign it to the vector
            // that holds the repo of movies
            sortResults = sortHolder->sort(searchResults);
            again = false;
        }
    } while (again);
    movie->printMovies(sortResults);
    movie->freeInstance();
    return 0;
}

