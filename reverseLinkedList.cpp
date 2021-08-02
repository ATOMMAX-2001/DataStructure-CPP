#include <iostream>

using namespace std;
class Node{
	public:
		int data;
		Node* next;
		void push_node(Node* head,int value)
		{
			if(head->data==-1){
				head->data=value;
			}else{
				Node* ptr= head;
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
		void print_node(Node* head)
		{
			Node* ptr= head;
			while(ptr!=NULL)
			{
				cout<<ptr->data;
				if(ptr->next!=NULL)
					cout<<" -> ";
				ptr=ptr->next;
			}
			cout<<endl;
		}
		void reverse_node(Node** head)
		{
			Node* ptr=*head;
			Node* pastPtr=*head;
			Node* futPtr=*head;
			while(ptr->next!=NULL && futPtr->next!=NULL)
			{
				futPtr=ptr->next;
				if(ptr==pastPtr){
					ptr->next=NULL;
				}else{
					ptr->next=pastPtr;
				}
				pastPtr=ptr;
				ptr=futPtr;
			}
			ptr->next=pastPtr;
			*head=ptr;
			
		}
} node;
int main()
{
	Node* head = new Node();
    head->data=-1;
    head->next=NULL;
    node.push_node(head,1);
    node.push_node(head,2);
    node.push_node(head,3);
    node.push_node(head,4);
    node.push_node(head,5);
    node.print_node(head);
    node.reverse_node(&head);
    node.print_node(head);
}
