#include "binary_trees.h"
/**
 * binary_tree_find_node - find node
 * @root: pointer
 * @node: pointer
 * Return: int
 */
int binary_tree_find_node(const binary_tree_t *root, const binary_tree_t *node)
{
	int found_left, found_right;

	if (root == NULL || node == NULL)
		return (0);
	if (root == node)
		return (1);
	found_left = binary_tree_find_node(root->left, node);
	found_right = binary_tree_find_node(root->right, node);
	return (found_left || found_right);
}

/**
 * binary_trees_ancestor -  function that finds the lowest
 * common ancestor of two nodes
 * @first: pointer
 * @second: pointer
 * Return: pointer
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	while (first != NULL)
	{
		if (binary_tree_find_node(first, second))
			return ((binary_tree_t *)first);
		first = first->parent;
	}
	return (NULL);
}
