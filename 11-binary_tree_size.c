#include "binary_trees.h"

void update_size(const binary_tree_t *tree, size_t *size);

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	update_size(tree, &size);
	return (size);
}

/**
 * update_size - Updates the size of a binary tree
 * @tree: Pointer to the root node of the tree or subtree
 * @size: Pointer to the size of the tree (to be updated)
 * Return: Nothing.
 */
void update_size(const binary_tree_t *tree, size_t *size)
{
	if (!tree)
		return;

	(*size)++;

	update_size(tree->left, size);
	update_size(tree->right, size);
}
