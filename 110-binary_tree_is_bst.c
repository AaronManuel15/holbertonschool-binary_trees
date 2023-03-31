#include "binary_trees.h"
#include <limits.h>

/**
 * isBSTUtil - Checks if a binary tree is a valid Binary Search Tree
 *
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 *
 * Return: maximum value from tree
 */

int isBSTUtil(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	return (isBSTUtil(tree->left, min, tree->n - 1)
		   &&
		   isBSTUtil(tree->right, tree->n + 1,
					 max));
}
/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (isBSTUtil(tree, INT_MIN, INT_MAX))
		return (1);
	else
		return (0);
}
