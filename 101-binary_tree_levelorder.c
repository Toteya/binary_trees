#include "binary_trees.h"

void traverse(binary_tree_t *tree, void (*func)(int), size_t level, int *done);

/**
 * binary_tree_levelorder - Traverses a binary tree using level order traversal
 * @tree: Pointer to the root node of the binary tree
 * @func: A pointer to a function to be called on each node
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int done = 0;
	size_t level = 0;

	if (!tree || !func)
		return;

	while (!done)
	{
		done = 1;
		traverse((binary_tree_t *) tree, func, level, &done);
		level++;
	}
}
/**
 * traverse - Traverses a binary tree or subtree
 * @tree: Pointer to the tree or subtree
 * @func: Function to be called on a node
 * @level: The depth of the current node in the tree.
 * @done: Flag indicating that the traversal of the entire tree is complete.
 * (0 means traversal is not yet complete)
 * Return: Nothing.
 */
void traverse(binary_tree_t *tree, void (*func)(int), size_t level, int *done)
{
	if (!tree)
		return;

	if (level == 0)
	{
		func(tree->n);
		*done = 0;
		return;
	}
	traverse(tree->left, func, level - 1, done);
	traverse(tree->right, func, level - 1, done);
}
