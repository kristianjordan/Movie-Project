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
    cout << "3. Search by Rating (G, PG, PG-13, R, NC-17)." << endl;
    cout << "4. Search by Mood." << endl << endl;
}

void displaySortMenu()
{
    cout << endl << "Enter how you would like to sort (#1-3):" << endl;
    cout << "1. Sort by Genre." << endl;
    cout << "2. Sort by Duration." << endl;
    cout << "3. Sort by Rating (G, PG, PG-13, R, NC-17)." << endl << endl;
}

void displayMoodMenu()
{
    cout << endl << "Enter your mood:" << endl;
    cout << "1. Happy." << endl;
    cout << "2. Sad." << endl;
    cout << "3. Neutral" << endl << endl;
}

int main() {
    // creating instance of MovieContext
    MovieContext * movie = MovieContext::getInstance();


    cout << endl << endl << setw(40) << "Moodvie Recommender" << endl;
    cout << setw(52) << "By: Kristian Jordan, Selena Arias, Gary Zeng" << endl << endl;

    char mood;
    bool again = false;
    vector<Movie*> moodResults;

    char search;
    vector<Movie*> searchResults;
    vector<Movie*> sortSearchResults;
    vector<Movie*> sortMoodResults;
    do
    {
        displaySearchMenu();
        cin >> search;
        if ((search < '1') || (search > '4'))
        {   cin.clear();	
            again = true;
            cout << "Invalid input. Try again.";
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    
	
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
        else if (search == '4')
        {
            displayMoodMenu();
            cin >> mood;
            if ((mood < '1') || (mood > '3'))
            {   cin.clear();
                again = true;
                cout << "Invalid input. Try again.";
		 cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }

            else if (mood == '1')
            {
                SearchStrategy * searchList = new SearchMood(); // create pointer to SearchRating strategy
                movie->setSearchStrategy(searchList); // set strategy in MovieContext to SearchRating
                SearchStrategy* search = movie->getSearchStrategy(); // create another SearchStrategy pointer
                vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers
                // and assign it to the vector
                moodResults = search->search(movieList, "happy");
                again = false;
            }
            else if (mood == '2')
            {
                SearchStrategy * searchList = new SearchMood(); // create pointer to SearchRating strategy
                movie->setSearchStrategy(searchList); // set strategy in MovieContext to SearchRating
                SearchStrategy* search = movie->getSearchStrategy(); // create another SearchStrategy pointer
                vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers
                // and assign it to the vector
                moodResults = search->search(movieList, "sad");
                again = false;
            }
            else if (mood == '3')
            {
                SearchStrategy * searchList = new SearchMood(); // create pointer to SearchRating strategy
                movie->setSearchStrategy(searchList); // set strategy in MovieContext to SearchRating
                SearchStrategy* search = movie->getSearchStrategy(); // create another SearchStrategy pointer
                vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers
                // and assign it to the vector
                moodResults = search->search(movieList, "neutral");
                again = false;
            }
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
        {   cin.clear();
            again = true;
            cout << "Invalid input. Try again.";
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');

        }
        if (sort == '1')
        {
            SortStrategy * sortList = new SortGenre();
            movie->setSortStrategy(sortList);
            SortStrategy * sortHolder = movie->getSortStrategy();
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers and assign it to the vector
            // that holds the repo of movies
            sortSearchResults = sortHolder->sort(searchResults);
            sortMoodResults = sortHolder->sort(moodResults);
            again = false;
        }
        else if (sort == '2')
        {
            SortStrategy * sortList = new SortDuration();
            movie->setSortStrategy(sortList);
            SortStrategy * sortHolder = movie->getSortStrategy();
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers and assign it to the vector
            // that holds the repo of movies
            sortSearchResults = sortHolder->sort(searchResults);
            sortMoodResults = sortHolder->sort(moodResults);
            again = false;
        }
        else if (sort == '3')
        {
            SortStrategy * sortList = new SortRating();
            movie->setSortStrategy(sortList);
            SortStrategy * sortHolder = movie->getSortStrategy();
            vector<Movie*> movieList = movie->getMovie(); // create new vector of Movie pointers and assign it to the vector
            // that holds the repo of movies
            sortSearchResults = sortHolder->sort(searchResults);
            sortMoodResults = sortHolder->sort(moodResults);
            again = false;
        }
    } while (again);
    movie->printMovies(sortMoodResults);
    movie->printMovies(sortSearchResults);
    movie->freeInstance();
    return 0;
}

