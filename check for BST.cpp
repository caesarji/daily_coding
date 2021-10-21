#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
     
   
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

    Node* getMax(Node* root){
        if(root->left==NULL) return NULL;
        Node* temp=root->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    Node* getMin(Node* root){
        if(root->right==NULL) return NULL;
        Node* temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    bool isBST(Node* root) 
    {
        cout<<"checking "<<root->data<<endl;
        if(!root) return true;
        Node* lmax=getMax(root);
        if(lmax!=NULL && root->data <= lmax->data) return false;
        Node* rmin=getMin(root);
        if(rmin!=NULL && root->data >= rmin->data) return false;
        if(root->left!=NULL && !isBST(root->left)) return false;
        if(root->right!=NULL && !isBST(root->right)) return false;
        
        return true;
        
    }
int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    // cout<<"here";
    if(isBST(root)==true) cout<<"true";
    // cout<<getMax(root)->data<<endl;
    // cout<<getMin(root)->data<<endl;
}