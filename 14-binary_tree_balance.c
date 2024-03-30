#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = 1, right_height = 1;
		
		if (tree->left)
			left_height += binary_tree_height(tree->left);
		if (tree->right)
			right_height += binary_tree_height(tree->right);
		return (left_height > right_height ? left_height : right_height);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, the function returns 0.
 *         Otherwise, returns the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
