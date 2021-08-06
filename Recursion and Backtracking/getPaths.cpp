#include<bits/stdc++.h>
using namespace std;

/*
	Problem: 
	
	Give a list of paths that can be taken such tha you can traverse the stairs using those given paths

*/	
list<string> getPaths(int n){
	
	// Base Case 
	
	if(n == 0){
		list<string> res;
		res.push_front("");
		return res;
	}
	else if(n < 0){
		list<string> res;
		return res;
	}
	
	list<string> path1 = getPaths(n-1);
	list<string> path2 = getPaths(n-2);
	list<string> path3 = getPaths(n-3);
	
	list<string> paths;
	
	for(auto path: path1){
		paths.push_front("1"+path);
	}
		
	for(auto path: path2){
		paths.push_front("2"+path);
	}
		
	for(auto path: path3){
		paths.push_front("3"+path);
	}
	
	return paths;
}

int main(){
	int n;
	cin >> n;
	
	list<string> ans = getPaths(n);
	
	
	for(auto path : ans){
		cout << path << " ";
	}
	cout << endl;
}
