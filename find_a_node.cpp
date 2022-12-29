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
bool isNodePresent(BinaryTreeNode<int> *root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    else if(root->data!=x){
        bool left_mei_present=isNodePresent(root->left,x);
        if(left_mei_present==true){
            return true;
        }
        else{
            bool right_mei_present=isNodePresent(root->right,x);
            if(right_mei_present==true){
                return true;
            }
            else{
                return false;
            }
        }
    }
}