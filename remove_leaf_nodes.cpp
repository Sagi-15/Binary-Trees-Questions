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
void removeLeafNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        root=NULL;
        return;
    }
    removeLeafNodes(root->left);
    removeLeafNodes(root->right);
}