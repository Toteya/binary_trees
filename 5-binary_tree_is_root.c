#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node of a binary node is the root node
 * @node: The node to be checked
 *
 * Return: 1 if the node is a root. Otherwise return 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);

	return (1);
}
