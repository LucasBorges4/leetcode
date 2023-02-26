#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//o problema consiste em verificar se a soma das raizes é igual 

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

bool checkTree(struct TreeNode* root){
    if (root->val == root->left->val + root->right->val) return true;
    return false;
}