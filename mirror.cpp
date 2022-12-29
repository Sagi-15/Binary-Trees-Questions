#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data=0){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
BinaryTreeNode<int>* helper_fucntion(BinaryTreeNode<int> *root){
    if(root==NULL){
        return NULL;
    }
    BinaryTreeNode<int> *left_subtree_root_after_reverse=helper_fucntion(root->left);
    BinaryTreeNode<int> *right_subtree_root_after_reverse=helper_fucntion(root->right);
    root->left=right_subtree_root_after_reverse;
    root->right=left_subtree_root_after_reverse;
    return root;
}
void mirrorBinaryTree(BinaryTreeNode<int>* root){
    helper_fucntion(root);//just call ussi se change
}