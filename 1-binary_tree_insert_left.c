#include "binary_trees.h"
/**
 * binary_tree_insert_left - Write a function that inserts at left node
 * @parent: pointer to node
 * @value: value to be inserted
 * Return: pointer to node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
	}
	parent->left = new_node;
	return (new_node);
}
