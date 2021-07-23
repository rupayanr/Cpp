#include <bits/stdc++.h>
using namespace std;

/* 

	Implement a priority Queue and define all the methods required for it
	

*/


class PriorityQ{
		
	public:
		
	
	vector<int> data;
	
	PriorityQ(){
		cout << "Priority Queue Initialized"<< endl;
	};
	
	void upHeapify(int i){
		int pi = get_parent(i);
		cout << "Parent: " << pi<<endl;
		
		if(data[i] < data[pi]){
			
			swap(data[i], data[pi]);
			upHeapify(pi);
		}
	};
	
	
	void downHeapify(int pi){
		
		int mini = data[pi];
		
		int left = data.at(get_left_child(pi));
		int right = data.at(get_right_child(pi));
		
		if(get_left_child(pi) < data.size() && left < mini){
			mini = left;
		}   
		
		if(get_right_child(pi) < data.size() && right < mini){
			mini = right;
		} 		
		
		if(mini != data[pi]){
			swap(mini,data[pi]);
			downHeapify(mini);
		}
		
		
	};
	
	void swap(int &a, int &b){

		int temp = a;
		a = b;
		b = temp;

	};
	
	int get_parent(int i){
		int pi = (i - 1)/2;
		if(pi >= 0){
			return pi;	
		}
		
	};
	
	
	int get_left_child(int pi){
		int lc = 2*pi + 1;
		
		if(lc < data.size()){
			return lc;	
		}
		
	};
	
	
	int get_right_child(int pi){
	    int rc = 2*pi + 2;
		
		if(rc < data.size()){
			return rc;	
		}
		
	};
	
	int peek(){
		if(data.size() == 0){
			cout << "Priority Queue is Empty"<<endl;
			return -1;
		}
		else{
			return data[0];
		}
	}
	
	int size(){
		return data.size();
	}
	
	void add(int val){
		
		/* ALGO
			1) Append val to vector
			2) Call Upheapify
		*/
		
		data.push_back(val);
		upHeapify(data.size() - 1); 
		//upHeapify(val);
	}
	
	void remove(){
		
		/* 
			ALGO
			1) Swap(first, last)
			2) Pop_back(last)
			3) DownHeapify(first) 
		
		*/
		
		swap(data.front(), data.back());
		data.pop_back();
		downHeapify(0);
		
	}
	
	void display(){
		for(auto el: data){
			cout << el << " ";
		}
		
		cout << endl;
	}
	
	
	
	
	
	
};



int main(){
	
	PriorityQ pq = PriorityQ();
	pq.add(10);
	pq.add(25);
	pq.add(35);
	pq.add(45);
	pq.display();
	
	pq.add(12);
	pq.display();
	
	pq.remove();
	pq.display();
	
	
	
}
