#include "binary_trees.h"
#include <stdio.h>

void update_height(const binary_tree_t *tree, size_t level, size_t *height);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: The root node of the binary tree
 *
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	balance_factor = (int) (left_height - right_height);

	return (balance_factor);
}


/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t level, height;

	if (!tree)
		return (0);

	level = 1;
	height = 1;

	update_height(tree, level, &height);
	return (height);
}

/**
 * update_height - Traverse the entire binary tree and updates the tree height.
 * @tree: The tree or subtree to be traversed
 * @level: The current level of the tree or subtree
 * @height: Pointer to the height of the tree (to be updated)
 *
 * Return:
 */
void update_height(const binary_tree_t *tree, size_t level, size_t *height)
{
	if (!tree)
		return;

	if (level > *height)
		*height = level;

	update_height(tree->left, level + 1, height);
	update_height(tree->right, level + 1, height);
}
