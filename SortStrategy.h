#ifndef _SORTSTRATEGY_H
#define _SORTSTRATEGY_H
#include <vector>
using namespace std;
/*
 * ***********************************************************************************
 * SortStrategy abstract class that sort strategies will inherit from
 * NOT yet complete, waiting on partners to implement this code
 * ************************************************************************************
 */
class SortStrategy
{
public:
    virtual vector<Movie*> sort(vector<Movie*>) = 0;
};

class SortGenre : public SortStrategy
{
public:
    vector<Movie*> sort(vector<Movie*> m)
    {
        cout << "Sort by genre" << endl;
        return m;
    }
};

class SortRating : public SortStrategy
{
public:
    vector<Movie*> sort(vector<Movie*> m)
    {
        cout << "Sort by rating" << endl;
        return m;
    }
};

class SortDuration : public SortStrategy
{
public:
    vector<Movie*> sort(vector<Movie*> m)
    {
        cout << "Sort by duration" << endl;
        return m;
    }
};
#endif //_SORTSTRATEGY_H
