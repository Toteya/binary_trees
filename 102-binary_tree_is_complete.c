#include "binary_trees.h"

void check(binary_tree_t *bt, int *complete, int *lf_lvl, int lvl, int *low);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to be checked
 *
 * Return: 1 if the tree is complete. Otherwise return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *bt;
	int is_complete = 1;
	int leaf_level = 0;
	int level = 0;
	int low_leaf = 0;

	if (!tree)
		return (0);

	bt = (binary_tree_t *) tree;
	check(bt, &is_complete, &leaf_level, level, &low_leaf);
	return (is_complete);
}

/**
 * check - Checks if a binary tree or subtree is complete
 * @bt: The tree or subtree to be checked
 * @complete: Flag indicating that the binary tree is complete
 * @lf_lvl: highest depth of a leaf recorded in the traversal
 * @lvl: The depth/level of the current node
 * @low: Flag indicating existance of a leaf(s) lower the lf_lvl
 *
 * Return: Nothing.
 */
void check(binary_tree_t *bt, int *complete, int *lf_lvl, int lvl, int *low)
{
	if (!complete)
		return;

	if (!bt)
	{
		if (lvl == *lf_lvl)
			*low = 1;
		return;
	}

	if (!bt->left && bt->right)
	{
		*complete = 0;
		return;
	}

	if (lvl > *lf_lvl && *lf_lvl)
	{
		*complete = 0;
		return;
	}

	if (lvl == *lf_lvl && *low)
	{
		*complete = 0;
		return;
	}

	if (!bt->left && !bt->right && !*lf_lvl)
		*lf_lvl = lvl;

	check(bt->left, complete, lf_lvl, lvl + 1, low);
	check(bt->right, complete, lf_lvl, lvl + 1, low);
}
