#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort -	sorts an array of ints in ascending order
 *					using Counting sort
 * @array: pointer to first element
 * @size:  number of elements
 *
 * Description: counts occurrences of each value in the array,
 *              builds a cumulative count, places
 *				each value in its correct position in the output array,
 *				and copies the output back to the original array.
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i, *count, *output;

	if (!array || size < 2)					/* NULL or invalid size */
		return;

	for (i = 0; i < (int)size; i++)			/* find max value */
		if (array[i] > max)
			max = array[i];

	count = calloc(max + 1, sizeof(int));	/* allocate count array */
	output = calloc(size, sizeof(int));
	if (!count || !output)					/* failure check */
	{
		free(count);
		free(output);
		return;
	}

	for (i = 0; i < (int)size; i++)			/* count occurrences */
		count[array[i]]++;

	for (i = 1; i <= max; i++)				/* cumulative count */
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = (int)size - 1; i >= 0; i--)	/* place elements in output */
		output[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)			/* copy back to OG array */
		array[i] = output[i];

	free(output);
	free(count);
}
