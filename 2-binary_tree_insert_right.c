#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new binary_tree node as a right child
 * of another node
 * @parent: Pointer to the parent node
 * @value: The integer data value to be stored by the new node
 *
 * Return: A pointer to the new node. Otherwise NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (new_node);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	if (parent->right)
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
	}
	parent->right = new_node;

	return (new_node);
}
