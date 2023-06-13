#include "binary_trees.h"
/**
 * binary_tree_depth - measure depth
 * @tree: pointer
 * Return: size_t
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	depth = 0;
	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * is_perfect_recursive - recursive function in c
 * @tree: pointer
 * @depth: depth
 * @level: level
 * Return: int
 */

int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);
	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - binary tree perfect ideal
 * @tree: pointer
 * Return: int
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	depth = binary_tree_depth(tree);
	return (is_perfect_recursive(tree, depth, 0));
}
