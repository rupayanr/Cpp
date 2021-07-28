#include<bits/stdc++.h>

using namespace std;

class Stack{
	
	public: 
	int* arr;
	int top = -1;
	
	Stack(int size){
		arr = new int[size];
	}
	
	void push(int val){
		
		top++;
		arr[top] = val;
	}
	
	
	void pop(){
		if(isEmpty()){
			return;
		}
		
		int val = arr[top];
		top--;
	}
	
	
	bool isEmpty(){
		if(top == -1){
			cout << "Stack is Empty"<<endl;
			return true;
		}
		return false;
	}
	
	
	int peek(){
		if(isEmpty()){
			return 0;
		}
		return arr[top];
	}
	
	
	void count(){
		cout << top + 1;
	}
	
	void display(){
		
		if(isEmpty()){
			return;
		}
		cout << "Stack (Top to Bottom): "<<endl;
		
		for(int i=top; i>=0; i--){
			cout << arr[i] <<endl;
		}
	}
	
};


void insert(Stack &s, int target){
	
	if(s.isEmpty() || s.peek() <= target){
		s.push(target);
		return;
	}
	
	int val = s.peek();
	
	s.pop();
	insert(s,target);
	s.push(val);	
	
}

void sort(Stack &s){
	
	// Base Case 
	if(s.isEmpty()) return;
	
	int last = s.peek();
	s.pop();
	
	sort(s);
	
	insert(s,last); 
	
}


int main(){
	
	Stack s = Stack(10);
	s.push(30);
	s.push(10);
	s.push(30);
	s.push(26);
	s.push(15);
	

	s.display();
	
	sort(s);
	
	s.display();
	
	
	
}
