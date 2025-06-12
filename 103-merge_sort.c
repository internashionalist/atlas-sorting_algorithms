#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - sorts an array of integers in ascending order
 *              using the top-down Merge Sort algorithm
 * @array: pointer to the array to sort
 * @size: number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

/**
 * merge_sort_recursive - recursive helper for merge_sort
 * @array: original array to sort
 * @buffer: temporary buffer array for merging
 * @left: starting index
 * @right: ending index
 */
void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, buffer, left, mid);
	merge_sort_recursive(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge - merges two sorted halves of the array
 * @array: original array
 * @buffer: temporary buffer array
 * @left: left index
 * @mid: midpoint index
 * @right: right index (exclusive)
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_subarray(array, left, mid);
	printf("[right]: ");
	print_subarray(array, mid, right);

	while (i < mid && j < right)
		buffer[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < mid)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_subarray(array, left, right);
}

/**
 * print_subarray - prints elements of the array between two indices
 * @array: array to print from
 * @start: starting index
 * @end: ending index (exclusive)
 */
void print_subarray(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
