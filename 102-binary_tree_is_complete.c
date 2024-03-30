#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_leaf = 0;
	int is_complete = 1;
	binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	queue[rear++] = (binary_tree_t *)tree;
	
	while (rear - front > 0)
	{
		binary_tree_t *current = queue[front++];
		
		if (current->left)
		{
			if (is_leaf)
				is_complete = 0;
			queue[rear++] = current->left;
		}
		else
		{
			is_leaf = 1;
		}

		if (current->right)
		{
			if (is_leaf)
				is_complete = 0;
			queue[rear++] = current->right;
		}
		else
		{
			is_leaf = 1;
		}
	}

	return (is_complete);
}

