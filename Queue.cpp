#include <bits/stdc++.h>
#define N 10
using namespace std;

class Queue{
	
		int* arr;
		int front;
		int rear;
		int count;
		
	
	public: 

		
		Queue(int size){
			arr = new int[size];
			front = 0;
			rear = -1;
		};
		
		int get_front(){
			return arr[front];
		}
		
		int get_rear(){
			return arr[rear];
		}
	
		
		bool isEmpty(){
			if(rear == -1){
				
				return true;
			}
			return false;
		}
		
		bool isFull(){
			if(rear == N-1){
				return true;
			}
			return false;
			
		}
		
		void display(){
			
			if(isEmpty()){
				cout << "Queue is Empty" <<endl;
				exit;
			}
			int temp = rear;
			while(temp >= front){
				cout << arr[temp] << " ";
				temp--;
			}
			cout<<end;
		};
		
		
		void enq(int val){
			
			if(isFull()){
				cout << "Queue is Full"<<endl;
				exit;
			}
			rear++;
			arr[rear] = val;
			count++;
				
		}
		
		void deq(){
			
			if(isEmpty()){
				cout << "Queue is Empty"<<endl;
				exit;
			}
			
			cout <<"Deleted :" << arr[front]<<endl;
			front += 1;
			count--;
			
		};
		

};

int main(){
	
	Queue q(5);
	q.enq(10);
	q.enq(22);
	q.enq(-2);
	
	q.display();
	q.deq();
	q.display();
	
	
}
