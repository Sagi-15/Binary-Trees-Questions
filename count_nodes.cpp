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
int count(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int number_of_nodes_in_left_subtree=count(root->left);
    int number_of_nodes_in_right_subtree=count(root->right);
    return 1+number_of_nodes_in_left_subtree+number_of_nodes_in_right_subtree;
}