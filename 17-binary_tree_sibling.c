#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: NULL if no sibling, else pointer to sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	sibling = node->parent->left;
	if (sibling == node)
		sibling = node->parent->right;
	if (sibling == NULL)
		return (NULL);
	return (sibling);
}
