#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm and the Knuth sequence.
 * @array: pointer to the first element of the array
 * @size:  number of elements in the array
 *
 * Description: uses gap sequence n = n * 3 + 1
 *              ( …, 121, 40, 13, 4, 1 ). After each gap
 *              reduction, the current state of the array
 *              is printed with print_array.
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* find largest gap with Knuth */
	while (gap < size / 3)
		gap = gap * 3 + 1; /* 1, 4, 13, 40, 121, ... */

	/* reduce gap */
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		/* insertion sort in gaps */
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}

		/* print current state of array */
		print_array(array, size);
		if (gap == 1)
			break;
	}
}
