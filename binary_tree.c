#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_tree_node {
  int value;
  struct _tag_tree_node *left;
  struct _tag_tree_node *right;
} tree_node;

tree_node *tree_root = NULL;

tree_node* create_new_node(int num) {
  tree_node *tree_new;
  
  tree_new = (tree_node*)malloc(sizeof(tree_node));
  if (tree_new == NULL) {
    exit(EXIT_FAILURE);
  }
  tree_new->left = NULL;
  tree_new->right = NULL;
  tree_new->value = num;
  return tree_new;
}

void insert_tree(int num, tree_node *node) {
  if (node == NULL) {
    tree_root = create_new_node(num);
    return;
  }

  if (node->value > num) {
    if (node->left != NULL) {
      insert_tree(num, node->left);
    } else {
      node->left = create_new_node(num);
    }
  } else {
    if (node->right != NULL) {
      insert_tree(num, node->right);
    } else {
      node->right = create_new_node(num);
    }
  }
}

tree_node* find_value(tree_node* node, int val) {
  if (node->value > val) {
    if (node->left == NULL) {
      return NULL;
    }
    return find_value(node->left, val);
  }
  if (node->value < val) {
    if (node->right == NULL) {
      return NULL;
    }
    return find_value(node->right, val);
  }
  return node;
}

int delete_tree(int val) {
  tree_node *node, *parent_node;
  tree_node *left_biggest;
  int direction;
  node = tree_root;
  parent_node = NULL;
  direction = 0;

  while (node != NULL && node->value != val) {
    if (node->value > val) {
      parent_node = node;
      node = node->left;
      direction = -1;
    } else {
      parent_node = node;
      node = node->right;
      direction = 1;
    }
  }

  if (node == NULL) {
    return 0;
  }

  if (node->left == NULL || node->right == NULL) {
    if (node->left == NULL) {
      if (direction == -1) {
        parent_node->left = node->right;
      }
      if (direction == 1) {
        parent_node->right = node->right;
      }
      if (direction == 0) {
        tree_root = node->right;
      }
    } else {
      if (direction == -1) {
        parent_node->left = node->left;
      }
      if (direction == 1) {
        parent_node->right = node->left;
      }
      if (direction == 0) {
        tree_root = node->left;
      }
    }
    free(node);
  } else {
    left_biggest = node->left;
    parent_node = node;
    direction = -1;
    while(left_biggest->right != NULL) {
      parent_node = left_biggest;
      left_biggest = left_biggest->right;
      direction = 1;
    }

    node->value = left_biggest->value;
    if (direction == -1) {
      parent_node->left = left_biggest->left;
    } else {
      parent_node->right = left_biggest->left;
    }
    free(left_biggest);
  }
  return 1;
}

int main() {
  printf("binary tree");
  return 0;
}