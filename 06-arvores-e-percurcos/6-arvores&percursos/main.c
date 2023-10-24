#include <stdio.h>
#include <stdlib.h>

#define COUNT 10
#include "tree.h"

// Defining Tree Structure
typedef struct tree
{
    char data;
    struct tree *left;
    struct tree *right;
} Tree;

Tree* create_empty_tree(void)
{
    return NULL;
}

Tree* create_tree(char data, Tree* l, Tree* r)
{
    Tree* tree = malloc(sizeof(Tree));
    tree->data = data;
    tree->left = l;
    tree->right = r;
    return tree;
};

Tree* free_tree(Tree* t)
{
    if(!is_empty(t))
    {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
    return NULL;
};

int is_empty(Tree* t)
{
    return (t == NULL);
};

int is_present(Tree* t, char data)
{
    if(!is_empty(t))
    {
        if(t->data == data)
        {
            return 1;
        }
        int found = is_present(t->left, data);
        if(!found)
        {
            found = is_present(t->right, data);
        }
        return found;
    }
    else
    {
        return 0;
    }
};

void print_tree(Tree* t)
{
    if(!is_empty(t))
    {
        printf("%c ", t->data);
        print_tree(t->left);
        print_tree(t->right);
    };
};

void print_binary_tree(Tree* t)
{
    if(is_empty(t))
    {
        printf("<> ");
    }
    else
    {
        printf("<");
        printf("%c ", t->data);
        print_binary_tree(t->left);
        print_binary_tree(t->right);
        printf("> ");
    };
};

int is_mirror(Tree* tree_a, Tree* tree_b)
{
    if(is_empty(tree_a) && is_empty(tree_b))
    {
        return 1;
    }

    if(is_empty(tree_a) || is_empty(tree_b))
    {
        return 0;
    }

    return ((tree_a->data == tree_b->data) && is_mirror(tree_a->left, tree_b->right) && is_mirror(tree_a->right, tree_b->left));
};

Tree* create_mirror(Tree* tree)
{
    if(is_empty(tree))
    {
        return NULL;
    }
    Tree* t = create_tree(tree->data, tree->right, tree->left);
    if(!is_empty(tree->left) )
    {
        t->right = create_mirror(tree->left);
    }
    if(!is_empty(tree->right))
    {
        t->left = create_mirror(tree->right);
    }
    return t;
};

Tree* create_copy(Tree* tree)
{
    if(is_empty(tree))
    {
        return NULL;
    }
    Tree* r = create_tree(tree->data, tree->left, tree->right);
    if(!is_empty(tree->left))
    {
        r->left = create_copy(tree->left);
    }
    if(!is_empty(tree->right))
    {
        r->right = create_copy(tree->right);
    }
    return r;
}

// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// Helper function to allocates a new node
Tree* newTree(char data)
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->data = data;
    tree->left = tree->right = NULL;
    return tree;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Tree* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Tree* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main()
{
    printf("=============================================== START ==\n");
    Tree *a, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9;
    a1 = create_tree('d', create_empty_tree(), create_empty_tree());
    a9 = create_tree('g', create_empty_tree(), create_empty_tree());
    a2 = create_tree('b', a9, a1);
    a3 = create_tree('e', create_empty_tree(), create_empty_tree());
    a4 = create_tree('f', create_empty_tree(), create_empty_tree());
    a5 = create_tree('c', a3, a4);
    a6 = create_tree('u', a2, a5);
    a7 = create_tree('z', create_empty_tree(), create_empty_tree());
    a8 = create_tree('x', a7, create_empty_tree());
    a  = create_tree('a', a6, a8);

    Tree *copy = create_copy(a);
    Tree *mirror = create_mirror(a);
//    printf("Tree a: \n");
//    print2D(a);
//    printf("\n");
//    printf("Tree copy: \n");
//    print2D(copy);
//    printf("\n");
//    printf("Tree mirror: \n");
//    print2D(mirror);
//    printf("\n");

    printf("a %s a\n", is_mirror(a, a) ? " is mirror of " : " is not mirror of ");
    printf("a %s copy\n", is_mirror(a, copy) ? " is mirror of " : " is not mirror of ");
    printf("a %s mirror\n", is_mirror(a, mirror) ? " is mirror of " : " is not mirror of ");

    printf("=============================================== END ==\n");
    return 0;
}
