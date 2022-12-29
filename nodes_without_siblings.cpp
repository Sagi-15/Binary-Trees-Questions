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
void printNodesWithoutSibling(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    else if(root->left!=NULL and root->right==NULL){
        cout<<root->left->data<<" ";
    }
    else if(root->right!=NULL and root->left==NULL){
        cout<<root->right->data<<" ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}