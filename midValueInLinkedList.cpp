#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(){
		data=-1;
		next=NULL;
	}
	void push_node(Node* head,int value)
	{
		if(head->data==-1){
			head->data=value;
		}else{
			Node* ptr = head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			Node* newNode = new Node();
			newNode->data=value;
			newNode->next=NULL;
			ptr->next=newNode;
		}

	}
	void print_middle(Node* head)
	{
		Node* ptr=head;
		Node* futPtr=head;
		while(futPtr!=NULL && futPtr->next!=NULL){
			ptr=ptr->next;
			futPtr=futPtr->next->next;
		}
		cout<<"Middle Element is "<<ptr->data<<endl;
	}
	void print_node(Node* head)
	{		
		Node* ptr= head;
		while(ptr!=NULL){
			cout<<ptr->data;
			if(ptr->next!=NULL){
				cout<<" -> ";
			}
			ptr=ptr->next;
		}
		cout<<endl;
	}
} node;

int main()
{	

    Node* head = new Node();
    node.push_node(head,1);
    node.push_node(head,2);
    node.push_node(head,3);
    node.push_node(head,4);
    node.push_node(head,5);

    node.print_node(head);
    node.print_middle(head);
    
}
