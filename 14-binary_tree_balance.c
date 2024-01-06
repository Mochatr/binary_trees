#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL
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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/*Initialize Balance factor*/
	int bfactor;

	if (tree == NULL)
		return (0);

	bfactor = binary_tree_height(tree->left) - binary_tree_height(tree->right);

	return (bfactor);
}
