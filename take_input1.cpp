#include <iostream>
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
void printTree(BinaryTreeNode<int> *root){
    //base case need here
    if(root==NULL){
        return; 
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        /*then need to print root ka child aur tell recursion
        to print the subtree*/
        /*abhi recursion not call as pehle left subtree
        print se pehle right child of root ie. apna kaam pehle
        khatam karna padhta*/
        cout<<"L "<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R "<<root->right->data;
    }
    cout<<endl;
    /*ab apna kaam khatam root ke respect mei sab done
    ab recursion call woh subtree print karega*/
    printTree(root->left);//pehle left subtree print
    printTree(root->right);
}
BinaryTreeNode<int>* take_input(){
    int rootData;
    cout<<"Enter node data : ";
    cin>>rootData;
    if(rootData==-1){
        return NULL; //user does'nt want to enter tree
    }
    //not -1 =>root made as woh hamara kaam
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    /*Now ask recursion to take input of left
    subtree and connect root->left to head of left subtree*/
    BinaryTreeNode<int> *left_child=take_input();
    //now connect root to this
    root->left=left_child;
    /*similarly for right subtree*/
    BinaryTreeNode<int> *right_child=take_input();
    root->right=right_child;
    return root;
}
int main(){
    BinaryTreeNode<int> *root=take_input();
    printTree(root);
}