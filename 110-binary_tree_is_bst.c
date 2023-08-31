#include "binary_trees.h"

void traverse_tree(binary_tree_t *tree, int *is_bst);
void check_is_bst(binary_tree_t *node, int rv, int *bst, int (*cmp)(int, int));
int cmp_ge(int num1, int num2);
int cmp_le(int num1, int num2);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * (BST)
 * @tree: Pointer to the root node of the binary tree to be checked
 *
 * Return: 1 if the tree is a valid BST. Otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 1;

	if (!tree)
		return (0);

	traverse_tree((binary_tree_t *)tree, &is_bst);

	return (is_bst);
}

/**
 * traverse_tree - Traverses the tree
 * @tree: The tree to be traversed
 * @is_bst: Flag indicating whether the binary tree still satisfies the
 * condition of a BST.
 * Return: Nothing.
 */
void traverse_tree(binary_tree_t *tree, int *is_bst)
{
	if (!tree || !*is_bst)
		return;

	check_is_bst(tree->left, tree->n, is_bst, cmp_ge);
	check_is_bst(tree->right, tree->n, is_bst, cmp_le);

	traverse_tree(tree->left, is_bst);
	traverse_tree(tree->right, is_bst);
}

/**
 * check_is_bst - Checks if a node satisfied the conditions of a valid BST
 * @node: The node to be checked
 * @rv: The value of the root node
 * @bst: Flag indicating whether the binary tree still satisfies the
 * condition of a BST.
 * @cmp: A comparison function to be called on the node depending on which
 * side of the root it is (left or right).
 * Return: Nothing.
 */
void check_is_bst(binary_tree_t *node, int rv, int *bst, int (*cmp)(int, int))
{
	if (!node || !*bst)
		return;

	if (cmp(node->n, rv))
	{
		*bst = 0;
		return;
	}

	check_is_bst(node->left, rv, bst, cmp);
	check_is_bst(node->right, rv, bst, cmp);
}

/**
 * cmp_ge - Compares if one integer is greater than or equal to another
 * @num1: The first number
 * @num2: The second number
 *
 * Return: 1 if num1 is greater or equal to num2. Otherwise returns 0.
 */
int cmp_ge(int num1, int num2)
{
	return (num1 >= num2);
}

/**
 * cmp_le - Compares if one integer is less than or equal to another
 * @num1: The first number
 * @num2: The second number
 *
 * Return: 1 if num1 is less than or equal to num2. Otherwise returns 0.
 */
int cmp_le(int num1, int num2)
{
	return (num1 <= num2);
}
