#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: A pointer to the root node of the BST
 * @value: The value to remove from the BST
 *
 * Return: A pointer to the new root node of the BST after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        if (root->left == NULL) {
            bst_t *tmp = root->right;
            free(root);
            return (tmp);
        } else if (root->right == NULL) {
            bst_t *tmp = root->left;
            free(root);
            return (tmp);
        }

        bst_t *min_right = root->right;
        while (min_right->left != NULL)
            min_right = min_right->left;

        root->n = min_right->n;
        root->right = bst_remove(root->right, min_right->n);
    }

    return (root);
}

