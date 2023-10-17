#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct tree Tree;

Tree* create_empty_tree(void);
Tree* create_tree(char data, Tree* l, Tree* r);
Tree* free_tree(Tree* t);
int is_empty(Tree* t);
int is_present(Tree* t, char data);
void print_tree(Tree* t);

// This week's exercise:

int is_mirror(Tree* tree_a, Tree* tree_b);
Tree*  create_mirror(Tree* tree);

#endif // TREE_H_INCLUDED
