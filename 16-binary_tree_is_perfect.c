#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0,
 * otherwise returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right
		if (tree->left)
		left = 1 + binary_tree_height(tree->left);
		return (left > right ? left : right);
	}
	else
	return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: If tree is NULL, the function returns 0, otherwise returns the size.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
else
return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL, the function returns 0, otherwise returns 1 if
 *         the tree is perfect, otherwise returns 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	perfect_size = (1 << (height + 1)) - 1;
	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
