#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: The list to be sorted
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 *
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev) /* if node1 has a prev */
		node1->prev->next = node2; /* set prev's next to node2 */
	else
		*list = node2; /* otherwise set list to node2 */

	if (node2->next) /* if node2 has a next */
		node2->next->prev = node1; /* set next's prev to node1 */

	node1->next = node2->next; /* set node1's next to node2's next */
	node2->prev = node1->prev; /* set node2's prev to node1's prev */
	node1->prev = node2; /* set node1's prev to node2 */
	node2->next = node1; /* and now I've confused myself again */
}



/**
 * insertion_sort_list - sorts a doubly linked list of integers 
 * in ascending order using the insertion sort algorithm, printing
 * the list after each swap
 * @list: The list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
