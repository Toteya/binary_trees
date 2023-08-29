#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node of a binary tree.
 * @tree: Pointer to the node to be measured
 *
 * Return: The depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *current_node;

	if (!tree)
		return (0);

	current_node = (binary_tree_t *) tree;
	while (current_node->parent)
	{
		depth++;
		current_node = current_node->parent;
	}

	return (depth);
}
