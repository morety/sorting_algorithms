#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - sort values in the  sub-array with respect to the 
 * the Bitonic-sort_algorithm
 * @up:thesorting directions
 * @array:the sort to subarray
 * @size:the  size of the subarray
 * done by :Temesgen Abdissa
 * Return: void(nothing)
 */
void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, dist;
	int swap;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == up)
		{
			swap = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swap;
		}
	}
}

/**
 * bitonic_merge - recursive of the  function that merges 2 sub-arrays
 * @up: the  sorting directions
 * @array:  the sub-array to sort
 * @size:thesub-array size 
 * done by :Temesgen Abdissa
 * Return: void(nothing)
 */
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - recursive funcusing the Bitonic-sort-algorithm
 * @up:  the direction of sorting
 * @array: the  sort subarray.
 * @size: the size of  sub-array.
 * @t: the size of  original array.
 * done by:Temesgen Abdissa
 * Return: void (nothing)
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - sorts  array of ints in ascending order using
 * the Bitonic-sort_algorithm
 * @array:  sort the array.
 * @size:  the size of the array
 * done by :Temesgen Abdissa
 * Return: void(nothing)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
