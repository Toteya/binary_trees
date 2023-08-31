#include "binary_trees.h"

void search(bst_t *tree, int value, bst_t **match_node);

/**
 * bst_search - Searches a BST for a value
 * @tree: Pointer to the root node of the BST
 * @value: The value to be searched for
 *
 * Return: A pointer to the node containing the match
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *match_node = NULL;

	search((bst_t *)tree, value, &match_node);
	return (match_node);
}

/**
 * search - Searches a binary tree for a node with the matching value
 * @tree: Pointer to the tree or subtree to be searched
 * @value: The value to be searched for
 * @match_node: Double pointer to the matching node
 * Return: Nothing
 */
void search(bst_t *tree, int value, bst_t **match_node)
{
	if (!tree || *match_node)
		return;

	if (value == tree->n)
	{
		*match_node = tree;
		return;
	}
	if (value < tree->n)
		search(tree->left, value, match_node);
	else
		search(tree->right, value, match_node);
}
