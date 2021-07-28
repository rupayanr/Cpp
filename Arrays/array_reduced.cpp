#include <bits/stdc++.h>
using namespace std;


void display( vector<pair<int,int>> vec ) {
	
	for(auto el: vec){
		cout << el.first << " " << el.second<<endl;
	}
}


void reduce_array(int a[], vector<pair<int,int>> vec,int len){
	
	for( int i=0; i < vec.size(); i++ ){
		a[vec[i].second] = i;
	}
	
 	for(int i=0; i<len; i++){
 		cout << a[i] << " ";
 	}
}

bool compare(pair<int,int> a, pair<int,int> b){
	
	return a.first < b.first;
}

int main(){
	
	// Given an array reduce it with its sorted index values 
	
	//Sample i/p {12, 6 , 20, 45, 12} { 2,0,3,4,1}
	
	int a[] = {15,6, 20, 45, 19, 2,12}; // { 3 1 5 6 4 0 2 }
	int len = sizeof(a)/sizeof(a[0]);
	
	vector<pair<int,int>> vec;
	
	for(int i=0; i<len;i++){
		vec.push_back(make_pair(a[i],i));
	}
	
	display(vec);
	sort(vec.begin(), vec.end(), compare);
	cout << "Sorted :" << endl;
	display(vec);
	
	reduce_array(a,vec,len);
	
	
	
}
