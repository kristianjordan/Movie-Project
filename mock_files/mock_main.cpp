#include "mock_movie.hpp"
#include "../sortstrategy.hpp"

#include <iostream>

using namespace std;

int main()
{
	Movie m1("5");
	Movie m2("6");
	Movie m3("100");
	Movie m4("5");
	Movie m5("21");
	Movie m6("1");
	Movie m7("6");
	vector<Movie> m = {m1, m2, m3, m6, m7, m5, m4};

	for(Movie i : m)
	{
		cout << i.get_rating() << ", ";
	}
	cout << endl;

	SortStrategy* ss = new SortRatings;
	vector<Movie> mList = ss->sort(m);

	for(Movie i : mList)
	{
	cout << i.get_rating() << ", ";
	}
}

