#ifndef _SEARCHSTRATEGY_H
#define _SEARCHSTRATEGY_H
#include <vector>
using namespace std;
/*
 *  * ***********************************************************************************
 *  * SearchStrategy abstract class that search strategies will inherit from
 *  * NOT yet complete, waiting on partners to implement this code
 *  * ************************************************************************************
 * 
 */
class SearchStrategy
{
public:
    virtual vector<Movie*> search(vector<Movie*>, string) = 0;
};

class SearchGenre : public SearchStrategy
{
public:
    vector<Movie*> search(vector<Movie*> m, string s)
    {
        cout << "Search by genre" << endl;
        return m;
    }
};

class SearchTitle : public SearchStrategy
{
public:
    vector<Movie*> search(vector<Movie*> m, string s)
    {
        cout << "Search by title" << endl;
        return m;
    }
};

class SearchRating : public SearchStrategy
{
public:
    vector<Movie*> search(vector<Movie*> m, string s)
    {
        cout << "Search by title" << endl;
        return m;
    }
};
#endif //_SEARCHSTRATEGY_H
