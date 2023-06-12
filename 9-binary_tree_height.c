#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary
 * @tree: pointer to root
 * Return: signed int 
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}