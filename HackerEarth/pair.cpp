#include<bits/stdc++.h>

using namespace std;

int main(){
	
	
	//Pairs 
	
	pair<int,string> p;
	//p = make_pair(4,"Birthday");
	p={4,"Birthdate"};
	cout << p.first << " " << p.second;
	
	pair <int,string> &p1 = p;
	
	cout << p1.first << p1.second;

	
	
	//Vectors (Dynamic Array)
	vector<int> v;
	int n,x;
	cin >> n;
	
	for(int i=0;i< n;i++){
		cin >> x;
		v.push_back(x);
	}
	
	for(auto i : v){
		cout<<i;
	}
	
	
	// Always pass reference of the 
	//vector or array to a function to avoid copying
	
}
