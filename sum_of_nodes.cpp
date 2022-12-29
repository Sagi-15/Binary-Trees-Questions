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
int getSum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int left_subtree_sum=getSum(root->left);
    int right_subtree_sum=getSum(root->right);
    return root->data+left_subtree_sum+right_subtree_sum;
}