#include "binary_trees.h"

/**
 * binary_tree_size1 - measures the size of a binary tree
 *
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: 0 if tree is NULL, number of nodes in the tree
 */
size_t binary_tree_size1(const binary_tree_t *tree)
{
	int nodeCountLeft = 0;
	int nodeCountRight = 0;

	if (tree == NULL)
		return (0);
	nodeCountLeft = binary_tree_size1(tree->left);
	nodeCountRight = binary_tree_size1(tree->right);
	return (nodeCountLeft + nodeCountRight + 1);
}

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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_height = binary_tree_height1(tree->left);
	right_height = binary_tree_height1(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 *
 * @tree: Pointer to the root node of the tree to check from
 *
 * Return: 0 if tree is NULL or not perfect, 1 if perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size;
	int height;

	if (tree == NULL)
		return (0);
	size = binary_tree_size1(tree);
	height = binary_tree_height1(tree);
	if (size == (1 << (height + 1)) - 1)
		return (1);
	return (0);
}
