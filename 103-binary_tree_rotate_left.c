#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary_tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the new root node of the binary tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root;

	if (!tree)
		return (NULL);

	old_root = tree;
	new_root = tree->right;

	old_root->parent = new_root;
	new_root->parent = NULL;
	old_root->right = new_root->left;
	if (old_root->right)
		old_root->right->parent = old_root;
	new_root->left = old_root;

	return (new_root);
}
