#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: If tree is NULL or the node has no parent, returns 0.
 *         Otherwise, returns the depth of the node.
 *
 * Description: Measures the depth of a node in a binary tree by
 *              recursively calculating the depth of its parent nodes.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
