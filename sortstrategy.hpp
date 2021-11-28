#ifndef __SORT_STRATEGY_HPP
#define __SORT_STRATEGY_HPP

#include <string>
#include <vector>
#include <algorithm>

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
	public:
	virtual int sort_partition(std::vector<Movie*>& m, int start, int end)
	{
		int pivot = start + (end - start)/2;
		std::string pivotVal = m.at(pivot)->get_rating();
		int low = start, high = end;
		while(low <= high)
		{
			while(std::stod(m.at(low)->get_rating()) > std::stod(pivotVal))
			{
				++low;
			}
			while(std::stod(m.at(high)->get_rating()) < std::stod(pivotVal))
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
			while((m.at(low)->get_genre()).compare(pivotVal) < 0)
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
