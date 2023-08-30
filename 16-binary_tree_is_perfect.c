#include "binary_trees.h"

void check_perfect(binary_tree_t *bt, int *is_perfect, int *lf_dpth, int dpth);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree to be checked
 *
 * Return: 1 if binary tree is perfect. Otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 1, depth = 0, leaf_depth = 0;

	check_perfect((binary_tree_t *) tree, &is_perfect, &leaf_depth, depth);
	return (is_perfect);
}

/**
 * check_perfect - Checks if a binary tree or subtree is perfect
 * @bt: Pointer to the node of the tree or subtree
 * @is_perfect: Flag indicating whether the tree is perfect
 * @lf_dpth: the depth of the last leaf checked
 * @dpth: the depth of the current node
 * Return: Nothing.
 */
void check_perfect(binary_tree_t *bt, int *is_perfect, int *lf_dpth, int dpth)
{
	int is_leaf = 0;

	if (!bt || !is_perfect)
		return;

	if (!bt->left && !bt->right)
		is_leaf = 1;
	else if ((!bt->left && bt->right) || (bt->left && !bt->right))
	{
		*is_perfect = 0;
		return;
	}

	if (is_leaf)
	{
		if (dpth != *lf_dpth && *lf_dpth)
		{
			*is_perfect = 0;
			return;
		}
		*lf_dpth = dpth;
	}

	check_perfect(bt->left, is_perfect, lf_dpth, dpth + 1);
	check_perfect(bt->right, is_perfect, lf_dpth, dpth + 1);
}
