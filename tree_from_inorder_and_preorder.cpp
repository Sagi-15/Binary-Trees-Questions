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
void printLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL){
        return; 
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        BinaryTreeNode<int> *front_node=q.front();
        q.pop();
        cout<<front_node->data<<":";
        if(front_node->left!=NULL){
            cout<<"L:"<<front_node->left->data<<",";
            q.push(front_node->left);
        }
        else if(front_node->left==NULL){
            cout<<"L:-1,";
        }
        if(front_node->right!=NULL){
            cout<<"R:"<<front_node->right->data;
            q.push(front_node->right);
        }
        else if(front_node->right==NULL){
            cout<<"R:-1";
        }
        cout<<endl;
    }
}
int getIndex(int *A,int n,int element){
    for(int i=0;i<n;i++){
        if(A[i]==element){
            return i;
        }
    }
}
BinaryTreeNode<int>* helper_function(int *preorder,int *inorder,int preorder_start,int preorder_end,int inorder_start,int inorder_end,int length){
    /*base case also*/
    if(inorder_start>inorder_end){
        return NULL; //as empty array
    }
    int rootData=preorder[preorder_start];
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    int rootIndexInInorder;
    for(int i=inorder_start;i<=inorder_end;i++){
        if(inorder[i]==rootData){
            rootIndexInInorder=i;
        }
    }
    /*For left subtree*/
    int inorder_start_for_left_subtree;
    int inorder_end_for_left_subtree;
    int preorder_start_for_left_subtree;
    int preorder_end_for_left_subtree;
    /*For right subtree*/
    int inorder_start_for_right_subtree;
    int inorder_end_for_right_subtree;
    int preorder_start_for_right_subtree;
    int preorder_end_for_right_subtree;
    /*Now easy ones*/
    preorder_start_for_left_subtree=preorder_start+1;
    inorder_start_for_left_subtree=inorder_start;
    preorder_end_for_right_subtree=preorder_end;
    inorder_end_for_right_subtree=inorder_end;
    /*Now use of rootIndexinInorder ka kaam*/
    inorder_end_for_left_subtree=rootIndexInInorder-1;
    inorder_start_for_right_subtree=rootIndexInInorder+1;
    preorder_end_for_left_subtree=inorder_end_for_left_subtree-inorder_start_for_left_subtree+preorder_start_for_left_subtree;
    preorder_start_for_right_subtree=preorder_end_for_left_subtree+1;
    root->left=helper_function(preorder,inorder,preorder_start_for_left_subtree,preorder_end_for_left_subtree,inorder_start_for_left_subtree,inorder_end_for_left_subtree,length);
    root->right=helper_function(preorder,inorder,preorder_start_for_right_subtree,preorder_end_for_right_subtree,inorder_start_for_right_subtree,inorder_end_for_right_subtree,length);
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){
    return helper_function(preorder,inorder,0,preLength-1,0,preLength-1,preLength);
}
int main(){
    int preorder[7]={1,2,4,5,3,6,7};
    int inorder[7]={4,2,5,1,6,3,7};
    BinaryTreeNode<int> *root=buildTree(preorder,7,inorder,7);
    printLevelWise(root);
}