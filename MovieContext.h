#ifndef _MOVIECONTEXT_H
#define _MOVIECONTEXT_H

#include <fstream>
#include "Movie.h"
#include "search.hpp"
#include "sortstrategy.hpp"
#include <vector>
#include <sstream>

using namespace std;

/*
 * Context class that implements singleton design pattern
 */
class MovieContext
{
private:

    /*
     * private variables
     */
    SearchStrategy * searchStrategy = nullptr;
    SortStrategy * sortStrategy = nullptr;
    static vector<Movie*> movieList; // vector to hold movies
    static MovieContext * obj; // static pointer to MovieContext class

    /*
     * private functions
     */
    MovieContext(){}; // private constructor

    // private function that will separate data
    vector<string> tokenize (const string &s, char delim) {
        vector<string> result;
        stringstream ss(s);
        string item;

        while (getline (ss, item, delim)) {
            result.push_back (item);
        }

        return result;
    }

    // private function that will loop through, read in data, and populate the vector
    void readMovies()
    {
        /*
         * open csv only if csv exists.
         * if the csv it doesn't, output error message
         */
        string line = "";
        ifstream infile;
        infile.open("movie_metadata.csv");
        if (!infile.is_open())
        {
            cout << "The input file does not exist. ";
        }

        else{
            // ignore first row of data (column names)
            getline(infile, line);
            vector<string> data;
            while (getline(infile, line))
            {
                data.clear();
                data = tokenize(line, ',');
                Movie *movie = new Movie();
                movie->set_directorName(data[1]);
				stringstream intValue(data[3]);
                int duration = 0;
                intValue >> duration;
                movie->set_duration(duration);
                movie->set_actorName(data[6] + ", " + data[10] + ", " + data[14]);
				movie->set_genre(data[9]);
                movie->set_title(data[11]);
                movie->set_rating(data[21]);
                movieList.push_back(movie);
            }
            infile.close();
        }
    }

public:

    /*
     * getInstance() function allows only one instantiation of the
     * MovieContext object.
     */
    static MovieContext * getInstance()
    {
        if (obj == nullptr)
        {
            obj = new MovieContext();
        }
        return obj;
    }

    // function to return vector of movies
    vector<Movie*> getMovie()
    {
        // populate vector by calling readMovies() if vector is empty
        if (movieList.empty())
            readMovies();
        return movieList;
    }

    ~MovieContext()
     {
	for (int i = 0; i < movieList.size(); i++)
		delete movieList[i];
	delete sortStrategy;
	delete searchStrategy;	
     }

    static void freeInstance()
    {
        delete obj;
        obj = NULL;
    }


    /*
     * function that prints data
    */
    void printMovies (vector<Movie*> movies)
    {
        for (int row=0; row < movies.size(); row++)
        {
            cout << "Title: " << movies.at(row)->get_title() << "\n";
	    cout << "Genre: " << movies.at(row)->get_genre() << "\n";
            cout << "Rating: " << movies.at(row)->get_rating() << "\n";
            cout << "Director Name: " << movies.at(row)->get_directorName() << "\n";
            cout << "Actor Name: " << movies.at(row)->get_actorName() << "\n";
            cout << "Duration: " << movies.at(row)->get_duration() << "\n";
            cout << "\n";
        }
    }

    /*
     * setter and getter for searching
     */
    void setSearchStrategy(SearchStrategy *search)
    {
	if (searchStrategy != nullptr)
	{
		delete searchStrategy;
		searchStrategy = nullptr;
	}
        searchStrategy = search;
    }

    SearchStrategy * getSearchStrategy()
    {
        return searchStrategy;
    }

    /*
     * setter and getter for sorting
     */
    void setSortStrategy(SortStrategy *sort)
    {
	if (sortStrategy != nullptr)
        {
                delete sortStrategy;
                sortStrategy = nullptr;
        }
        sortStrategy = sort;
    }

    SortStrategy * getSortStrategy()
    {
        return sortStrategy;
    }
};

/*
 * required for initializing the singleton
 * design pattern
 */
MovieContext * MovieContext::obj = 0;
vector<Movie*> MovieContext::movieList;

#endif //MOVIECONTEXT_H

