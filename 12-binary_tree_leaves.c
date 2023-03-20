#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: 0 if tree is NULL, number of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leafCountLeft = 0;
	int leafCountRight = 0;

	if (tree == NULL)
		return (0);
	leafCountLeft = binary_tree_leaves(tree->left);
	leafCountRight = binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (leafCountLeft + leafCountRight);
}
