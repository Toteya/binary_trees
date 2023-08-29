#include "binary_trees.h"

void delete_subtree(binary_tree_t *tree);

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node;
 *
 * Return: Nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	delete_subtree(tree);
}

/**
 * delete_subtree - Deletes a node or subtree of binary tree
 * @tree: The root node of the subtree
 *
 * Return: Nothing.
 */
void delete_subtree(binary_tree_t *tree)
{
	if (tree->left)
		delete_subtree(tree->left);
	if (tree->right)
		delete_subtree(tree->right);

	free(tree);
}
