/*
 @Author: S.ABILASH
 comment: Just  for Learning
*/

#include<iostream>


using namespace std;

class Node{
public:
	int data;
	Node* next;

	void print_linked_list(Node* head){
		Node* ptr = head;
		while(ptr!=NULL){
			cout<<ptr->data;
			if(ptr->next!=NULL){
				cout<<" -> ";
			}
			ptr=ptr->next;			
		}
		delete ptr;		
	}

	void push_at_end(Node* head, int value)
	{
		if(head->data==-1){
			head->data=value;
		}else{
			Node* ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			Node* newNode = new Node();
			newNode->data=value;newNode->next=NULL;
			ptr->next=newNode;				
		}		
	}

	void push_after(Node* head,int position,int value)
	{
		if(head->next==NULL){
			cout<<"cannot insert new node in given position"<<endl;
		}else{	
			Node* ptr= head;
			int count=1;
			while(count!=position && ptr->next!=NULL){
				ptr=ptr->next;
				count++;
			}
			Node* newNode = new Node();
			newNode->data=value;
			newNode->next=ptr->next;
			ptr->next=newNode;
		}
	}

	void push_before(Node* head,int position,int value)
	{
		if(head->next==NULL || position==1){
			cout<<"Cannot insert new node in given position"<<endl;
		}else{
			Node* ptr = head;
			int count =1;
			while(count!=(position-1) && ptr->next!=NULL)
			{
				ptr=ptr->next;
				count++;
			}			
			Node* newNode = new Node();
			newNode->data=value;
			newNode->next=ptr->next;
			ptr->next=newNode;
		}
	}

	void push_at_start(Node** head,int value)
	{
		Node* ptr= *head;
		Node* newNode = new Node();
		newNode->data=value;
		newNode->next=ptr;
		*head=newNode;		
	}

	void delete_at_end(Node* head)
	{
		if(head->next==NULL){
			cout<<"cannot delete the last node";
		}else{
			Node* ptr= head;
			Node* pastPtr= head;
			while(ptr->next!=NULL)
			{
				pastPtr=ptr;
				ptr=ptr->next;
			}
			pastPtr->next=NULL;
			delete ptr;
		}
	}

	void delete_at_start(Node** head)
	{
		Node* ptr = *head;
		delete *head;
		*head=ptr->next;
	}
	void delete_after(Node* head,int position)
	{
		if(position==0){
			cout<<"cannot delete given node"<<endl;
		}else{
			Node* ptr=head;
			Node* pastPtr=head;
			int count=1;
			while(count!=position+1 && ptr->next!=NULL)	
			{
				pastPtr=ptr;
				ptr=ptr->next;
				count++;
			}	
			pastPtr->next=ptr->next;
			delete ptr;
		}
	}
	void delete_before(Node* head,int position)
	{
		if(position==1 || position==0){
			cout<<"cannot delete the given node"<<endl;
		}else{
			Node* ptr=head;
			Node* pastPtr=head;
			int count=1;
			while(count!=position-1 && ptr->next!=NULL)
			{
				pastPtr=ptr;
				ptr=ptr->next;
				count++;
			}			
			pastPtr->next=ptr->next;
			delete ptr;
		}
	}

	void display_node(Node* head,int position)
	{
		if(position==0){
			cout<<"cannot display the value of the given node"<<endl;
		}
		Node* ptr= head;
		int count=0;
		while(count!=position-1 && ptr->next)
		{
			ptr=ptr->next;
			count++;
		}
		cout<<"The Data stored in the node for given position is "<<ptr->data<<endl;

	}

}node;

int main()
{
	 
  	Node* head = new Node();
  	//inserting new node at the end of the linked list
	head->data=-1;head->next=NULL;
  	node.push_at_end(head,1);
  	node.push_at_end(head,2);
  	node.push_at_end(head,3);
  	node.push_at_end(head,4);
  	node.push_at_end(head,5);
 	node.print_linked_list(head);cout<<endl;

  	//insert a new node after the given position NOTE: starting node is considered as 1 here
  	node.push_after(head,3,6);
 	node.print_linked_list(head);cout<<endl;

	//insert a new node before the given position NOTE: starting node is considered as 1 here
	node.push_before(head,3,7);
 	node.print_linked_list(head);cout<<endl;

  	//insert a new node at the start of the linked list
  	node.push_at_start(&head,8);
  	node.print_linked_list(head);cout<<endl;

  	//delete the node at end
  	node.delete_at_end(head);
  	node.print_linked_list(head);cout<<endl;
	
  	//delete the head node
  	node.delete_at_start(&head);
  	node.print_linked_list(head);cout<<endl;

  	//delete the node after the given position NOTE: starting node is considered as 1 here
  	node.delete_after(head,2);
  	node.print_linked_list(head);cout<<endl;

  	//delete the node before the given position NOTE: starting node is considered as 1 here
  	node.delete_before(head,5);
 	node.print_linked_list(head);cout<<endl;

 	//display the data stored in the given position NOTE: starting node is considered as 1 here
 	node.display_node(head,3);
 	node.print_linked_list(head);cout<<endl;
  	delete head;  	  	

}
