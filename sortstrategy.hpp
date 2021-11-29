#ifndef __SORT_STRATEGY_HPP
#define __SORT_STRATEGY_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <map>

class SortStrategy
{
	public:
	virtual std::vector<Movie*> sort(std::vector<Movie*>) = 0;
};

//helper abstract class
class Sort : public SortStrategy
{
	public:
	virtual std::vector<Movie*> sort(std::vector<Movie*> m)
	{
		return quicksort(m, 0, m.size() - 1);
	}
	virtual std::vector<Movie*> quicksort(std::vector<Movie*>& m, int start, int end)
	{
		if(start < end)
		{
			int pivot = sort_partition(m, start, end);
			quicksort(m, start, pivot - 1);
			quicksort(m, pivot, end);
		} 
		return m;
	}
	virtual int sort_partition(std::vector<Movie*>&, int, int) = 0;
};

class SortRating : public Sort
{
	private:
	map<std::string, int> ratings = { {"Unrated", -1},
									{"TV-Y", 0},
									{"TV-Y7", 1},
									{"TV-FY FV", 2},
									{"G", 3},
									{"TV-G", 4},
									{"PG", 5},
									{"TV-PG", 6},
									{"PG-13", 7},
									{"TV-14", 8},
									{"R", 9},
									{"NC-17", 10},
									{"TV-MA", 11} };	
	public:
	virtual int sort_partition(std::vector<Movie*>& m, int start, int end)
	{
		int pivot = start + (end - start)/2;
		int pivotVal = ratings[m.at(pivot)->get_rating()];
		int low = start, high = end;
		while(low <= high)
		{
			while(ratings[m.at(low)->get_rating()] > pivotVal)
			{
				++low;
			}
			while(ratings[(m.at(high)->get_rating())] < pivotVal)
			{
				--high;
			}
			if(low <= high)
			{
				std::iter_swap(m.begin() + low, m.begin() + high);
				++low;
				--high;
			}
		}
		return low;
	}
};

class SortDuration : public Sort
{
	public:
	virtual int sort_partition(std::vector<Movie*>& m, int start, int end)
	{
		int pivot = start + (end - start)/2;
		int pivotVal = m.at(pivot)->get_duration();
		int low = start, high = end;
		while(low <= high)
		{
			while(m.at(low)->get_duration() > pivotVal)
			{
				++low;
			}
			while(m.at(high)->get_duration() < pivotVal)
			{
				--high;
			}
			if(low <= high)
			{
				std::iter_swap(m.begin() + low, m.begin() + high);
				++low;
				--high;
			}
		}
		return low;
	}
};

class SortGenre : public Sort
{	
	public:
	virtual int sort_partition(std::vector<Movie*>& m, int start, int end)
	{
		int pivot = start + (end - start)/2;
		std::string pivotVal = m.at(pivot)->get_genre();
		int low = start, high = end;
		while(low <= high)
		{
			while((m.at(low)->get_genre()).compare(pivotVal) < 0 )
			{
				++low;
			}
			while((m.at(high)->get_genre()).compare(pivotVal) > 0)
			{
				--high;
			}
			if(low <= high)
			{
				std::iter_swap(m.begin() + low, m.begin() + high);
				++low;
				--high;
			}
		}
		return low;
	}
};

#endif
