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

	if (tree == NULL)
		return (0);
	while (tree->left != NULL || tree->right != NULL)
	{
		if (tree->left != NULL)
		{
			tree = tree->left;
			height++;
		}
		else if (tree->right != NULL)
		{
			tree = tree->right;
			height++;
		}
	}
	return (height);
}
