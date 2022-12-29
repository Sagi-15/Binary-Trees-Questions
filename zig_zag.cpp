#include <iostream>
#include <stack>
#include <vector>
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
void zigZagOrder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> left_to_right,right_to_left;
    right_to_left.push(root);
    while((right_to_left.empty()==true and left_to_right.empty()==true)==false){
        if(right_to_left.empty()==true){
            while(left_to_right.empty()==false){
                BinaryTreeNode<int> *current=left_to_right.top();
                cout<<current->data<<" ";
                left_to_right.pop();
                if(current->right!=NULL){
                    right_to_left.push(current->right);
                }
                if(current->left!=NULL){
                    right_to_left.push(current->left);
                }
            }
            cout<<endl;
        }
        if(left_to_right.empty()==true){
            while(right_to_left.empty()==false){
                BinaryTreeNode<int> *current=right_to_left.top();
                cout<<current->data<<" ";
                right_to_left.pop();
                if(current->left!=NULL){
                    left_to_right.push(current->left);
                }
                if(current->right!=NULL){
                    left_to_right.push(current->right);
                }
            }
            cout<<endl;
        }
    }
}
