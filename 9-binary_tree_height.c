#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * post-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 0;
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		height = left_height;
	else
		height = right_height;
	return (height);
}
