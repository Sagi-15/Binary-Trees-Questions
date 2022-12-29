queue<BinaryTreeNode<int>*> copy_queue(queue<BinaryTreeNode<int>*> q){
    queue<BinaryTreeNode<int>*> p;
    while(q.empty()==false){
        p.push(q.front());
        q.pop();
    }
    return p;
}
void zigZagOrder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    bool isLevelEven=false;
    q.push(root);
    q.push(NULL);
    while((q.size()==1 and q.front()==NULL)==false){
        BinaryTreeNode<int> *current=q.front();
        cout<<current->data<<" ";
        q.pop();
        if(isLevelEven==true){
            vector<int> v;
            queue<BinaryTreeNode<int>*> copy=copy_queue(q);
            while(copy.front()!=NULL){
                v.push_back(copy.front()->data);
                copy.pop();
            }
            for(int i=v.size()-1;i>=0;i--){
                    cout<<v[i]<<" ";
            }
        }
        else if(isLevelEven==false){
            queue<BinaryTreeNode<int>*> copy=copy_queue(q);
            while(copy.front()!=NULL){
                cout<<copy.front()->data<<" ";
                copy.pop();
            }
        }
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
        if(q.empty()==false and q.front()==NULL){
            if(isLevelEven==true){
                isLevelEven=false;
            }
            else{
                isLevelEven=true;
            }
            q.pop();
            cout<<endl;
            q.push(NULL);
        }
    }
}