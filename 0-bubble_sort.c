#include "sort.h"

/**
 *bubble_sort - sortarray of intiger  in ascending order
 *@array:  numbers of array
 *@size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i;
	int num;

	if (array == NULL  || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				num = array[j];
				array[j] = array[j + 1];
				array[j + 1] = num;
				print_array(array, size);
			}
		}
	}
}
