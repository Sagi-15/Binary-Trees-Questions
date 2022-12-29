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
int absolute_difference(int a,int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}
pair<int,bool> isBalanced_helper(BinaryTreeNode<int> *root){
    /*int in pair stores height and bool stores if balanced or not*/
    if(root==NULL){
        pair<int,bool> answer;
        answer.first=0;
        answer.second=true;
        return answer;
    }
    pair<int,bool> left_subtree_answer=isBalanced_helper(root->left);
    pair<int,bool> right_subtree_answer=isBalanced_helper(root->right);
    if(absolute_difference(left_subtree_answer.first,right_subtree_answer.first)<=1 and (left_subtree_answer.second==true) and (right_subtree_answer.second==true)){
        pair<int,bool> answer;
        answer.first=1+max(left_subtree_answer.first,right_subtree_answer.first);
        answer.second=true;
        return answer;
    }
    else{
        pair<int,bool> answer;
        answer.first=1+max(left_subtree_answer.first,right_subtree_answer.first);
        answer.second=false;
        return answer;
    }
}
bool isBalanced(BinaryTreeNode<int> *root){
    return isBalanced_helper(root).second;
}