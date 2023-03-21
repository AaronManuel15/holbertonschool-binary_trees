#include "binary_trees.h"

/**
 * binary_tree_height1 - measures the height of a binary tree
 * post-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: height of the tree
 */
size_t binary_tree_height1(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_height = binary_tree_height1(tree->left);
	right_height = binary_tree_height1(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 *
 * @tree: Pointer to the root node of the tree to count from
 *
 * Return: 0 if tree is NULL, node difference count
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height1(tree->left) - binary_tree_height1(tree->right));
}
