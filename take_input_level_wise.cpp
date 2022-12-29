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
BinaryTreeNode<int>* take_input(){
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    else if(rootData!=-1){
        BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        while(q.empty()==false){
            BinaryTreeNode<int> *front_node=q.front();
            q.pop();
            int left_child_of_front;
            cout<<"Enter left child of "<<front_node->data<<" : ";
            cin>>left_child_of_front;
            if(left_child_of_front!=-1){
                BinaryTreeNode<int> *child=new BinaryTreeNode<int>(left_child_of_front);
                front_node->left=child;
                q.push(child);
            }
            int right_child_of_front;
            cout<<"Enter right child of "<<front_node->data<<" : ";
            cin>>right_child_of_front;
            if(right_child_of_front!=-1){
                BinaryTreeNode<int> *child=new BinaryTreeNode<int>(right_child_of_front);
                front_node->right=child;
                q.push(child);
            }
        }
        return root;
    }
}
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
int main(){
    BinaryTreeNode<int> *root=take_input();
    printLevelWise(root);
}