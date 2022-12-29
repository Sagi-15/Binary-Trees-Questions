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
int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int absolute_difference(int a,int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}
bool isBalanced(BinaryTreeNode<int> *root) {
	if(root==NULL){
        return true;
    }
    bool isBalanced_wrt_root=(absolute_difference(height(root->left),height(root->right))<=1);
    bool isBalanced_left_subtree=isBalanced(root->left);
    bool isBalanced_right_subtree=isBalanced(root->right);
    return isBalanced_wrt_root and isBalanced_left_subtree and isBalanced_right_subtree;
}