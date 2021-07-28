#include <bits/stdc++.h>
using namespace std;

class CircularQ{
	
	int *arr;
	int front;
	int rear;
	int size;
	int count = 0;
	
	public:
		
		CircularQ(int s){
			arr = new int[size];
			size = s;
			front = -1;
			rear = -1;
		}
		
		void get_size(){
			cout << "Size: "<<size<<endl;
		}
		
		void get_count(){
			cout << "Count: "<<count<<endl;
		}
		
		bool isEmpty(){
			if(front == -1){
				return true;
			}
			return false;
		};
		
		
		bool isFull(){

			if((rear + 1) % size == front){
				return true;
			}
			return false;

			
		};
		
		void display(){
			int temp = front;
			while(temp != rear){
				cout << arr[temp] << " ";
				temp = (temp + 1) % size;
			}
			cout <<arr[temp] << endl;
		};
		
		void enq(int val){
			
			if(isFull()){
				cout << "Queue is Full, Dequeue to remove value" <<endl;
			}
			else if(isEmpty()){
				front = rear = 0;
				arr[rear] = val;
				count++;
			}
			else{
				rear = (rear + 1) % size;
				arr[rear] = val;
				count++;				
			}
		

			
		};
		
		void deq(){
			
			if(isEmpty()){
				cout << "Queue is Empty, Enqueue to add value"<<endl;
			}
			int data = arr[front];
			cout << "Dequeued Data: "<<data<<endl;
			arr[front] = -1;
			front = (front + 1) % size;
			count--;
			
		}
		
};

int main(){
	
	CircularQ q(5);
	
	
	q.get_count();
	q.get_size();
	
	q.enq(4);
	q.enq(-1);
	q.enq(-28);
	q.enq(10);
	q.enq(92);
	
	q.display();
	
	q.get_count();
	q.get_size();
	
	q.deq();
	q.deq();
	
	
	q.get_count();
	q.get_size();
	q.display();
	
	q.enq(89);
	q.enq(18);
	q.display();
	q.get_count();
	q.get_size();

}
