#include "binary_trees.h"

void count_leaves(const binary_tree_t *tree, size_t *leaves);

/**
 * binary_tree_leaves - Counts the leaf nodes (leaves) of a binary tree.
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The number of leaf nodes
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	count_leaves(tree, &leaves);
	return (leaves);
}

/**
 * count_leaves - Counts the number of number of leaves of a subtree
 * @tree: The binary tree or subtree whose leaves are to be counted
 * @leaves: Pointer to the current leaves count (to be updates)
 *
 * Return: Nothing.
 */
void count_leaves(const binary_tree_t *tree, size_t *leaves)
{
	if (!tree)
		return;

	if (!tree->left && !tree->right)
		(*leaves)++;
	else
	{
		count_leaves(tree->left, leaves);
		count_leaves(tree->right, leaves);
	}
}
