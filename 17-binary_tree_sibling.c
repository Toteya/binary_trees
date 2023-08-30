#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node whose sibling is to be found
 *
 * Return: Pointer to the sibling of the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		sibling = node->parent->right;
	else
		sibling = node->parent->left;

	return (sibling);
}
