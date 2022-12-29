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
class Pair{
    public:
        BinaryTreeNode<int> *node;
        int level;
        Pair(BinaryTreeNode<int> *node=NULL,int level=0){
            this->node=node;
            this->level=level;
        }
};
void printLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    queue<Pair*> q;
    Pair *initial=new Pair(root,0);
    q.push(initial);
    while(q.empty()==false){
        Pair *current=q.front();
        q.pop();
        cout<<current->node->data<<" ";
        if(current->node->left!=NULL){
            Pair *left_child=new Pair(current->node->left,current->level+1);
            q.push(left_child);
        }
        if(current->node->right!=NULL){
            Pair *right_child=new Pair(current->node->right,current->level+1);
            q.push(right_child);
        }
        if(q.empty()==false and current->level+1==q.front()->level){
            cout<<endl;
        }
    }
}
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
int main(){
    BinaryTreeNode<int> *root=take_input();
    printLevelWise(root);
}