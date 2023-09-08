#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_insert_parent(*root);
	if (!parent)
	{
		free(new_node);
		return (NULL);
	}

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	return (heapify_up(new_node));
}

/**
 * find_insert_parent - Finds the parent node for inserting a new node
 * @root: A pointer to the root node of the Heap
 *
 * Return: A pointer to the parent node
 */
heap_t *find_insert_parent(heap_t *root)
{
	while (root->left && root->right)
	{
		if (root->left->n > root->right->n)
			root = root->left;
		else
			root = root->right;
	}
	return (root);
}

/**
 * heapify_up - Moves a newly inserted node up the heap if necessary
 * @node: The node to move up
 *
 * Return: A pointer to the node after the heapify operation
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}
