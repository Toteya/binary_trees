#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the binary tree to be rotated
 *
 * Return: A pointer to the new root node of the binary tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root;

	if (!tree)
		return (0);

	old_root = tree;
	new_root = tree->left;

	old_root->parent = new_root;
	old_root->left = new_root->right;
	new_root->right = old_root;

	return (new_root);
}
