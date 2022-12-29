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
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
  vector<Node<int> *> answer;
  if (root == NULL) {
    return answer;
  }
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  q.push(NULL);
  Node<int> *head = NULL, *tail = NULL;
  while ((q.size() == 1 and q.front() == NULL) == false) {
    BinaryTreeNode<int> *current = q.front();
    q.pop();
    if (head == NULL) {
      /*implies new level started in queue*/
      head = new Node<int>(current->data);
      tail = head;
    } else if (head != NULL) {
      /*implies same level continue in queue*/
      tail->next = new Node<int>(current->data);
      tail = tail->next;
    }
    if (current->left != NULL) {
      q.push(current->left);
    }
    if (current->right != NULL) {
      q.push(current->right);
    }
    if (q.front() == NULL) {
      q.pop();
      answer.push_back(head);
      head = NULL;
      tail = NULL;
      q.push(NULL);
    }
  }
  return answer;
}