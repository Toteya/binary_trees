#include "binary_trees.h"

void update_height(const binary_tree_t *tree, size_t level, size_t *height);

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

	level = 0;
	height = 0;

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
