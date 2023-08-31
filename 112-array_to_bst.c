#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: The array from which to build the binary search tree
 * @size: The size of the array
 *
 * Return: Pointer to the root node of the array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}

	return (tree);
}


