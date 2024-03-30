#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	while (head != NULL)
	{
		levelorder_queue_t *tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, frees the queue and exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t **head,
               levelorder_queue_t **tail, void (*func)(int))
{
	if (node == NULL || head == NULL || tail == NULL || func == NULL)
		return;
	func(node->n);
	if (node->left)
	{
		levelorder_queue_t *new_left = create_node(node->left);
		if (new_left == NULL)
		{
			free_queue(*head);
			exit(1);
		}
		(*tail)->next = new_left;
		*tail = new_left;
	}
	if (node->right)
	{
		levelorder_queue_t *new_right = create_node(node->right);
		if (new_right == NULL)
		{
			free_queue(*head);
			exit(1);
		}
		(*tail)->next = new_right;
		*tail = new_right;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	if (head == NULL || *head == NULL)
		return;
	levelorder_queue_t *tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	levelorder_queue_t *head = NULL, *tail = NULL;
	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;
	while (head != NULL)
	{
		pint_push(head->node, &head, &tail, func);
		pop(&head);
	}
}
