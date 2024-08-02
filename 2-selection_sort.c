#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order,
 * printing the array after each swap
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i; /* outer loop counter */
	size_t j; /* inner loop counter */
	size_t min; /* to hold minimum value */
	int temp; /* to hold swapped value */

	if (array == NULL || size < 2) /* if array is too small or NULL */
		return; /* return nothing */

	for (i = 0; i < size - 1; i++) /* loop through outer */
	{
		min = i; /* set min to current index */

		for (j = i + 1; j < size; j++) /* loop through inner */
		{
			if (array[j] < array[min]) /* if current < min */
				min = j; /* set min to current */
		}

		if (min != i) /* if min is not current */
		{
			temp = array[i]; /* set temp to current */
			array[i] = array[min]; /* set current to min */
			array[min] = temp; /* set min to temp */

			print_array(array, size); /* print the array */
		}
	}
}
