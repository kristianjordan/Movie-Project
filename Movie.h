#ifndef _MOVIE_H
#define _MOVIE_H
#include <string>
using namespace std;



/*
 * Movie class: holds attributes of movie
 * as well as getters and setters for them
 */
class Movie
{
private:
    // private attributes of a movie
    string title;
    string rating;
    string director_name;
    string actor_name;
    int duration;
    string genre;
public:

    /*
     * movie class setters
     */
    void set_title(string t)
    {
        title = t;
    }
    void set_rating(string r)
    {
        rating = r;
    }
    void set_directorName(string director)
    {
        director_name = director;
    }
    void set_actorName(string actor)
    {
        actor_name = actor;
    }
    void set_duration(int dur)
    {
        duration = dur;
    }
    void set_genre(string mood)
    {
        genre = mood;
    }    

    /*
     * movie class getters
     */
    string get_title()
    {
        return title;
    }
    string get_rating()
    {
        return rating;
    }
    string get_directorName()
    {
        return director_name;
    }
    string get_actorName()
    {
        return actor_name;
    }
    int get_duration()
    {
        return duration;
    }
    string get_genre()
    {
        return genre;
    }
};

#endif //_MOVIE_H

