/*
  Author:S.ABILASH
  Comment: Just For Learning
*/
#include <iostream>

using namespace std;

class Node{
public:	
	int data;
	Node* left;
	Node* right;
	Node(){
		data=-1;
		left=NULL;
		right=NULL;
	}
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
	Node* create_node(int value)
	{
		Node* newNode= new Node(value);
		return newNode;
	}
	void push_node(Node* head,int value)
	{
		Node* newNode=create_node(value);
		Node* pastPtr = NULL;
		if(head==NULL){
			head->data=value;
			head->left=NULL;
			head->right=NULL;
		}else{
			Node* ptr= head;
			while(ptr!=NULL)
			{
				pastPtr=ptr;
				if(value<ptr->data){
					ptr=ptr->left;
				}else{
					ptr=ptr->right;
				}
			}
			if(value<pastPtr->data){
				pastPtr->left=newNode;
			}else{
				pastPtr->right=newNode;
			}

		}		
	
	}
	int node_height(Node* root)
	{
		int leftHeight=0,rightHeight=0;
		if(root==NULL){
			return 0;
		}else{
			 leftHeight=node_height(root->left);
			 rightHeight=node_height(root->right);
			if(leftHeight>rightHeight){
				return leftHeight+1;
			}else{
				return rightHeight+1;
			}
		}
	}
	void preorder(Node* head){
		if(head!=NULL){
			cout<<head->data<<endl;
			preorder(head->left);
			preorder(head->right);
		}else{
			cout<<"NULL"<<endl;
		}
	}
	void inorder(Node* head){
		if(head!=NULL){
			inorder(head->left);
			cout<<head->data<<endl;
			inorder(head->right);
		}
	}
	void postorder(Node* head){
		if(head!=NULL){
			postorder(head->left);
			postorder(head->right);
			cout<<head->data<<endl;
		}
	}
} node;

int main()
{

   Node* root = new Node(45);
   node.push_node(root,39);
   node.push_node(root,78);
   node.push_node(root,54);
   node.push_node(root,79);
   node.push_node(root,56);
   node.push_node(root,80);
  
   node.preorder(root);

   cout<<"The Height Of the Tree is "<<node.node_height(root)<<endl;
}
