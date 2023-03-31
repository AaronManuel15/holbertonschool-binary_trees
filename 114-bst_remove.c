#include "binary_trees.h"
#include <limits.h>

/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 *
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	else if (tree->n > value)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 *
 * @root: pointer to the root node of the BST to search
 * @value: value to remove from the tree
 *
 * Return: pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value) {
    if (root == NULL) {
        // empty tree
        return NULL;
    } else if (value < root->n) {
        // value is in the left subtree
        root->left = bst_remove(root->left, value);
        return root;
    } else if (value > root->n) {
        // value is in the right subtree
        root->right = bst_remove(root->right, value);
        return root;
    } else {
        // found the node to remove
        if (root->left == NULL && root->right == NULL) {
            // node has no children
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // node has only a right child
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // node has only a left child
            bst_t *temp = root->left;
            free(root);
            return temp;
        } else {
            // node has two children
            bst_t *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->n = temp->n;
            root->right = bst_remove(root->right, temp->n);
            return root;
        }
    }
}
