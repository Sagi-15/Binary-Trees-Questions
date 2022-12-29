#include <iostream>
#include <queue>
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
template <typename T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node(T data=0){
            this->data=data;
            this->next=NULL;
        }
};
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root){
    vector<Node<int> *> answer;
    if(root==NULL){
        return answer;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    Node<int> *head=NULL,*tail=NULL;
    while((q.size()==1 and q.front()==NULL)==false){
        BinaryTreeNode<int> *current=q.front();
        q.pop();
        if(head==NULL){
            /*implies new level started in queue*/
            head=new Node<int>(current->data);
            tail=head;
        }
        else if(head!=NULL){
            /*implies same level continue in queue*/
            tail->next=new Node<int>(current->data);
            tail=tail->next;
        }
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
        if(q.front()==NULL){
            q.pop();
            answer.push_back(head);
            head=NULL;
            tail=NULL;
            q.push(NULL);
        }
    }
    return answer;
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
