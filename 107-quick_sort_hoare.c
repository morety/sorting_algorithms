#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - finds the partition for the quicksort using the Hoare scheme
 * @array:  the array to sort.
 * @lo: the  lowest index of the partition to sort.
 * @hi:  the highest index of the partition to sort.
 * @size: the  size of the array.
 * done by:temesgen abdissa.
 * Return: the  index of the partition.
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
