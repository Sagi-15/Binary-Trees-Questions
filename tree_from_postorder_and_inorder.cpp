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
BinaryTreeNode<int>* buildTreeHelper(int *postorder,int *inorder,int postorder_start,int postorder_end,int inorder_start,int inorder_end){
    if(postorder_start>postorder_end){
        return NULL;
    }
    int rootData=postorder[postorder_end];
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    int postorder_start_in_left_subtree;
    int postorder_end_in_left_subtree;
    int inorder_start_in_left_subtree;
    int inorder_end_in_left_subtree;
    int postorder_start_in_right_subtree;
    int postorder_end_in_right_subtree;
    int inorder_start_in_right_subtree;
    int inorder_end_in_right_subtree;
    /*Easy ones pehle*/
    postorder_start_in_left_subtree=postorder_start;
    inorder_start_in_left_subtree=inorder_start;
    postorder_end_in_right_subtree=postorder_end-1;
    inorder_end_in_right_subtree=inorder_end;
    int rootIndexInInorder;
    for(int i=inorder_start;i<=inorder_end;i++){
        if(inorder[i]==rootData){
            rootIndexInInorder=i;
        }
    }
    inorder_end_in_left_subtree=rootIndexInInorder-1;
    inorder_start_in_right_subtree=rootIndexInInorder+1;
    postorder_end_in_left_subtree=inorder_end_in_left_subtree-inorder_start_in_left_subtree+postorder_start_in_left_subtree;
    postorder_start_in_right_subtree=postorder_end_in_left_subtree+1;
    root->left=buildTreeHelper(postorder,inorder,postorder_start_in_left_subtree,postorder_end_in_left_subtree,inorder_start_in_left_subtree,inorder_end_in_left_subtree);
    root->right=buildTreeHelper(postorder,inorder,postorder_start_in_right_subtree,postorder_end_in_right_subtree,inorder_start_in_right_subtree,inorder_end_in_right_subtree);
    return root;
}
BinaryTreeNode<int>* buildTree(int *postorder,int postLength,int *inorder,int inLength){
    return buildTreeHelper(postorder,inorder,0,postLength-1,0,postLength-1);
}