#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes in a
 * binary tree
 * @first: The first node
 * @second: The second node
 *
 * Return: Pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *p_first, *p_second;

	if (!first || !second)
		return (NULL);

	p_first = (binary_tree_t *) first;
	while (p_first)
	{
		p_second = (binary_tree_t *) second;
		while (p_second)
		{
			if (p_first == p_second)
				return (p_first);
			p_second = p_second->parent;
		}
		p_first = p_first->parent;
	}

	return (NULL);
}
