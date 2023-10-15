#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    printf("=============================================== START ==\n");
    Tree *a, *a1, *a2, *a3, *a4, *a5;
    a1 = create_tree('d',create_empty_tree(),create_empty_tree());
    a2 = create_tree('b',create_empty_tree(),a1);
    a3 = create_tree('e',create_empty_tree(),create_empty_tree());
    a4 = create_tree('f',create_empty_tree(),create_empty_tree());
    a5 = create_tree('c',a3,a4);
    a  = create_tree('a',a2,a5);

//    print_tree(a);
//    printf("\n");
//    print_binary_tree(a);
//    printf("\n");
    printf("Is 'd' present? %s\n", is_present(a, 'd') ? "Yes." : "No.");
    printf("Is 'z' present? %s\n", is_present(a, 'z') ? "Yes." : "No.");
    printf("\n");


    printf("=============================================== END ==\n");
    return 0;
}
