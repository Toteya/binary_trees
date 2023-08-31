#include "binary_trees.h"

void insert_node(bst_t *node, bst_t *new_node, int *inserted);

/**
 * bst_insert - Inserts a new node into a binary search tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to be stored in the new node
 *
 * Return: A pointer to the new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	int inserted = 0;
	bst_t *new_node;

	new_node = malloc(sizeof(bst_t));
	if (!new_node)
		return (NULL);

	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}

	insert_node(*tree, new_node, &inserted);

	if (!inserted)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * insert_node - Inserts a node into a BST
 * @node: Pointer to the root node
 * @new_node: Pointer to the node to be inserted
 * @inserted: Flag indicating that a node has been succesfully inserted.
 *
 * Return: Nothing.
 */
void insert_node(bst_t *node, bst_t *new_node, int *inserted)
{
	if (new_node->n > node->n)
	{
		if (node->right)
			insert_node(node->right, new_node, inserted);
		else
		{
			node->right = new_node;
			new_node->parent = node;
			*inserted = 1;
		}
	}
	else if (new_node->n < node->n)
	{
		if (node->left)
			insert_node(node->left, new_node, inserted);
		else
		{
			node->left = new_node;
			new_node->parent = node;
			*inserted = 1;
		}
	}
}
