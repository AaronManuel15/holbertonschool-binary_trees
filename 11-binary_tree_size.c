#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: 0 if tree is NULL, number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int nodeCountLeft = 0;
	int nodeCountRight = 0;

	if (tree == NULL)
		return (0);
	nodeCountLeft = binary_tree_size(tree->left);
	nodeCountRight = binary_tree_size(tree->right);
	return (nodeCountLeft + nodeCountRight + 1);
}
