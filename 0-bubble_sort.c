#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order,
 * printing the array after each swap
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t inner; /* inner loop counter */
	size_t outer; /* outer loop counter */
	int temp; /* to hold swapped value */

	if (array == NULL || size < 2) /* if array is too small or NULL */
		return; /* return nothing, I guess */

	for (outer = 0; outer < size - 1; outer++) /* loop through outer */
	{
		for (inner = 0; inner < size - outer - 1; inner++) /* loop through inner */
		{
			if (array[inner] > array[inner + 1]) /* if current > next */
			{
				temp = array[inner]; /* set temp to current */
				array[inner] = array[inner + 1]; /* set current to next */
				array[inner + 1] = temp; /* set next to temp */
				print_array(array, size); /* print the array */
			}
		}
	}
}
