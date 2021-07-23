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
	
	long long numRev(Node *head){
		long long mul = 1;
		long long num = 0;
		Node *temp = head;
		
		while(temp != NULL){
			
			num += temp->data * mul;
			mul *= 10;
			temp = temp->next;
		}
		
		return num;
	}
	
	
	Node *result(Node *head1, Node *head2){
		

		int sum = numRev(head1) + numRev(head2);
		
		int rem = sum % 10;
		sum = sum / 10;
		
		Node *newHead = new Node(rem);
		Node *temp = newHead;
		
		while(sum != 0){
			
			rem = sum % 10;
			Node *aux = new Node(rem);
			temp->next = aux;
			temp = aux;
			
			sum = sum / 10;
		}
		
		
		return newHead;
	}
	
	
	bool isPalindrome(Node* head){
		
		Node *slow=head, *fast=head, *prev, *temp;
		
		while(fast && fast->next){
			
			slow = slow->next;
			fast = fast->next->next;
		
		}
		
		reverse(slow);
		fast = head;
		
		while(slow){
			
			if(fast->data != slow->data){
				return false;
			}
			else{
				fast = fast->next;
				slow = slow->next;
			}
		}
		
		return true;
		
		
		
	}
	
	
	Node *findSum(Node *l1, Node *l2){
		
		Node* dummy = new Node(0);
		Node* temp = dummy;
		
		int carry = 0;
		
		while(l1 || l2 || carry){
			
			int sum = 0;
			
			
			if(l1 != NULL){
				sum += l1->data;	
				l1 = l1->next;
			}
			
			if(l2 != NULL){
				sum += l2->data;	
				l2 = l2->next;	
			}

			sum += carry;
			
			Node *aux = new Node(sum%10);
			carry = sum / 10;
			
			temp->next = aux;
			temp = temp->next;
			
		}
		
		return dummy->next;
		
		
	}

int main(){
	
	vector<int> nums = {2,2,1};

	//[5,6,4] 
	
	
	Node *head1 = new Node(1);
	Node *head2 = new Node(5);
	
	for(int i=0; i<nums.size(); i++){
		append(head1,nums[i]);
	}
	show(head1);

	
	append(head2,6);
	append(head2,4);
	show(head2);
	

	
	Node *res = findSum(head1,head2);
	
	show(res);
	
	
	if(isPalindrome(head1)){
		cout << "yes";
	}
	else{
		cout << "no";
	}
	
	return 0;
	
}



