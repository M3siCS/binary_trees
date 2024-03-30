#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int level = 0;
	int nodes = 0;

	if (tree == NULL)
		return (0);

	while (tree)
	{
		nodes++;
		tree = tree->left;
	}

	while (tree && level < nodes)
	{
		if ((!tree->left && tree->right) || (tree->left && !tree->right))
			return (0);
		if (!tree->left && !tree->right && level < nodes - 1)
			return (0);
		level++;
		if (level < nodes && ((nodes >> (level - 1)) & 1))
			tree = tree->right;
		else
			tree = tree->left;
	}

	return (1);
}

