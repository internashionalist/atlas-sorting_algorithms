#include "sort.h"


/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp; /* to hold swapped value */

	temp = *a; /* set temp to first integer */
	*a = *b; /* set first integer to second integer */
	*b = temp; /* set second integer to temp */
}



/**
 * partition - Lomuto partition scheme for quick sort
 * @array: array of integers
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot; /* pivot value */
	int i; /* index of smaller element */
	int j; /* index of the partition */

	pivot = array[high]; /* set pivot to last element */
	i = low - 1; /* set smaller element index to lowest - 1 */

	for (j = low; j <= high - 1; j++) /* loop through array */
	{
		if (array[j] < pivot) /* if current element < pivot */
		{
			i++; /* increment smaller element index */
			if (i != j) /* if smaller element index != current index */
			{
				swap(&array[i], &array[j]); /* swap smaller element with current element */
				print_array(array, size); /* print the array */
			}
		}
	}
	if (i + 1 != high) /* if smaller element index + 1 != highest */
	{
		swap(&array[i + 1], &array[high]); /* swap smaller element + 1 with highest */
		print_array(array, size); /* print the array */
	}
	return (i + 1); /* return smaller element index + 1 */
}


/**
 * quick_sort_recursive - recursive function for quick sort
 * @array: array of integers
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot; /* index of the pivot */

	if (low < high) /* if lowest index < highest index */
	{
		pivot = partition(array, low, high, size); /* set pivot to partition index */
		quick_sort_recursive(array, low, pivot - 1, size); /* sort left side of pivot */
		quick_sort_recursive(array, pivot + 1, high, size); /* sort right side of pivot */
	}
}



/**
 * quick_sort - sorts an array of integers in ascending order
 * using quick sort algorithm, printing the array after each swap
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2) /* if array is too small or NULL */
		return; /* return nothing */
	
	quick_sort_recursive(array, 0, size - 1, size); /* sort the array */
}
