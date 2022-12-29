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
        int height;
        int diameter;
        Pair(){
            this->height=0;
            this->diameter=0;
        }
};
Pair diameterHeight(BinaryTreeNode<int> *root){
    if(root==NULL){
        Pair answer;
        return answer;//constructor nei dono ko 0 set
    }
    Pair left_ka_height_and_diameter=diameterHeight(root->left);
    Pair right_ka_height_and_diameter=diameterHeight(root->right);
    int option1=left_ka_height_and_diameter.height+right_ka_height_and_diameter.height;
    int option2=left_ka_height_and_diameter.diameter;
    int option3=right_ka_height_and_diameter.diameter;
    int answer_diameter=max(option1,max(option2,option3));
    Pair p;
    //agar chaho toh pair ke height mei overall height may daal 1+max(h1,h2) se but ni use uska
    p.diameter=answer_diameter;
    return p;
}
int diameter(BinaryTreeNode<int> *root){
    return diameterHeight(root).diameter;
}
