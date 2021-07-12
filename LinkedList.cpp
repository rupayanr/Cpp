#include <bits/stdc++.h>
using namespace std;

class Node {
	
	
public:
	int data; 
	Node *next;
	
	Node(int val){
		
		data = val;
		next = NULL;
	}

};

	
	bool isEmpty(Node *&head){
		
		if(head == NULL){
			return true;
		}
		else{
			return false;
		}
		
	}
	
	Node *reverse_rec(Node *&head){
		
		// O(1) time complexity 
		if(head==NULL || head->next==NULL){
			return head;	
		}
		
		Node *newHead = reverse_rec(head->next);
		head->next->next = head;
		head->next = NULL;
		
		return newHead;
		
		
	}
	
	
	void reverse(Node *&head){
		
		// WE NEED THREE POINTERS Prev Curr and Next	
		//First set next ptr to current's next node then current's next node should point to prev node 
		// prev node = current node, curr = next node, loop exit return prev 
		
		Node *prev = NULL;
		Node *curr = head;
		Node *nextptr;
		
		while(curr != NULL){
			
			// Set current next ptr to next node
			nextptr = curr->next;
				
			// Set current link to prev node 
			curr->next = prev;
			
			// Set prev = curr and curr = next 
			prev = curr;
			curr = nextptr;
			
		}
		
		head = prev;	
		
	}	
	
	
	
	void append(Node *&head,int val){
		
		Node *new_node = new Node(val);
		
		if(head == NULL){
			head = new_node;
		}
		
		Node *temp = head;
		while(temp->next!= NULL){
			
			temp = temp->next;
			
		}
		
		temp->next = new_node;
		
	}
	
	
	void addFirst(Node *&head, int val){
		
		Node *new_node = new Node(val);
		
		if(isEmpty(head)){
			head = new_node;	
		}
		new_node->next = head;
		head = new_node;
		
	}
	
	
	bool search(Node *head, int key){
		
		Node *temp = head;
		while(temp != NULL){
			if(temp->data == key){
				return true;
			}
			temp = temp->next;
		}
		return false;
		
	}
	
	void del(){
	
	}
	
	void show(Node *head){
		
		Node *temp = head;
		while(temp != NULL){
			
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout<<"Null"<<endl;
		
	}

int main(){
	
	
	Node *head = new Node(5);
	
	
	append(head,8);
	show(head);
	
	addFirst(head,10);
	append(head,29);
	show(head);
	
	reverse(head);
	show(head);
	
	Node *newhead = reverse_rec(head);
	show(newhead);
	return 0;
	
}



