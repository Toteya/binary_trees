#include "binary_trees.h"

void check_full_nodes(const binary_tree_t *tree, int *is_full);

/**
 * binary_tree_is_full - Checks whether a binary tree is full
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if tree is full. Otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (!tree)
		return (0);

	check_full_nodes(tree, &is_full);
	return (is_full);
}

/**
 * check_full_nodes - Checks if all the nodes of a binary tree or subtree
 * have either 2 or 0 children.
 * @tree: The tree or subtree
 * @is_full: Pointer to the flag indicating that the tree is full
 *
 * Return: Nothing.
 */
void check_full_nodes(const binary_tree_t *tree, int *is_full)
{
	if (!tree || !is_full)
		return;

	if (!((!tree->left && !tree->right) || (tree->left && tree->right)))
	{
		*is_full = 0;
		return;
	}
	check_full_nodes(tree->left, is_full);
	check_full_nodes(tree->right, is_full);
}

