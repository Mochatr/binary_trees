#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: O if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
	{
		height_left = binary_tree_height(tree->left);
		height_right = binary_tree_height(tree->right);

		return ((height_left > height_right ? height_left : height_right) + 1);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 0 if the tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (left_height == 0)
			return (1);

		return (binary_tree_is_perfect(tree->left)
				&& binary_tree_is_perfect(tree->right));
	}
	return (0);
}
