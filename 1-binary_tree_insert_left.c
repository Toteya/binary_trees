#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of another
 * binary tree node.
 * @parent: The parent node
 * @value: The int data value stored by the node
 *
 * Return: Pointer to the new node. Otherwise return NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	if (parent->left)
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
	}
	parent->left = new_node;

	return (new_node);
}
