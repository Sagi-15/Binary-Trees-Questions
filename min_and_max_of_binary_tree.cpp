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
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root){
    /*base case*/
    if(root==NULL){
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int,int> answer_from_left=getMinAndMax(root->left);
    pair<int,int> answer_from_right=getMinAndMax(root->right);
    pair<int,int> answer;
    answer.first=min(answer_from_left.first,min(answer_from_right.first,root->data));
    answer.second=max(answer_from_left.second,max(answer_from_right.second,root->data));
    return answer;
}