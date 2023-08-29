#include "binary_trees.h"

void count_parents(const binary_tree_t *tree, size_t *parents);

/**
 * binary_tree_nodes - Counts the number of nodes with at least one child node.
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Number of parent/non-leaf nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parents = 0;

	count_parents(tree, &parents);
	return (parents);
}

/**
 * count_parents - Counts the number of "parent" nodes in tree or subtree
 * @tree: The tree or subtree whose parent nodes are to be counted
 * @parents: Pointer to the current count of parent nodes
 *
 * Return: Nothing.
 */
void count_parents(const binary_tree_t *tree, size_t *parents)
{
	if (!tree || (!tree->left && !tree->right))
		return;

	(*parents)++;

	count_parents(tree->left, parents);
	count_parents(tree->right, parents);
}
