#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node of a binary tree is a leaf node
 * @node: The node to be checked
 *
 * Return: 1 if the node is a leaf. Otherwise return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!(node->left) && !(node->right))
		return (1);

	return (0);
}
