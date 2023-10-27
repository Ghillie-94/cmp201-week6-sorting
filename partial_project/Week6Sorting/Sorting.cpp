// CMP201.2022 AX1.4 Sorting
// William Kavanagh, Abertay University

#include "Sorting.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */
#include <iostream>
#include <chrono>		/* timing */
#include <string>

// Bubble up and bubble back down.
// Runs in O(N^2).
void CocktailShakerSort(int a[], int size)
{
	int temp;
	bool swap = true;
	int end = size - 1;
	int start = 0;
	// TODO: assessed, [1.0]
	while (swap)
	{
		for (int i = start; i < end; ++i)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swap = true;
			}
		}

		if (!swap)
		{
			break;
		}

		swap = false;
		--end;
		for (int j = end - 1; j >= start; --j)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swap = true;
			}
		}
		++start;
	}
	
}

// IN-PLACE implementation of insertion sort.
// Runs in O(N^2).
void InsertionSort(int a[], int size)
{
	// TODO: assessed, [1.5]
	int target; int i; int j;

	for (i = 1; i < size; ++i)
	{
		target = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > target)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = target;
	}

	
}

// Partition function for QuickSort.
// Runs in O(n) and chooses the final element as the pivot
int partition(int a[], int begin, int end)
{
	
	// TODO: assessed, [2.0]
	int i = begin - 1;
	int pivot = a[end];
	int temp;
	for (int j = begin; j <= end - 1; ++j)
	{
		if (a[j] <= pivot)
		{
			++i;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	temp = a[end];
	a[end] = a[i + 1];
	a[i + 1] = temp;

	return i + 1;
}

// Sorting using partition() and *recursion. Runs in O(n log(n))
void QuickSort(int a[], int begin, int end)
{
	
	// TODO: assessed, [0.5]
	if (begin < end)
	{
		int pi = partition(a, begin, end);
		QuickSort(a, begin, pi - 1);
		QuickSort(a, pi + 1, end);
	}
	
}

// Takes an array and it's size (as int), fills the array with random values from 1 to size*3
void fillArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % (size * 3);
	}

}

// Utility function: O(n) sorted check with early exit.
bool isSorted(int a[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

// Utility function: Get two time points and return a string of nanoseconds between them.
std::string timeDelta(std::chrono::steady_clock::time_point t, std::chrono::steady_clock::time_point t2)
{
	long timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t).count();
	return std::to_string(timeDelta) + " ns";
}


