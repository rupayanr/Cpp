#include<bits/stdc++.h>
using namespace std;

/*class Node{
	
};

*/
/*
void depth(unordered_map<int,vector<int>> &adList, int source){
	
	stack<int> stk;
	
	stk.push(source);
	
	while(!stk.empty()){
		int curr = stk.top();
		cout << curr << endl;
		stk.pop();
		
		for(auto el: adList[curr]){
			stk.push(el);
		}
	}
	
	
}
*/
/*
void depth(unordered_map<int,vector<int>> &adList, int source){
	
	cout << source << endl;
	
	for(auto el: adList[source]){
		depth(adList, el);
	}
}
*/


int main(){
	//unordered_map<Node,vector<Node>> adList;
	
	unordered_map<int,vector<int>> adList; 
	
	adList[1] = {2, 3};
	adList[2] = {5};
	adList[3] = {4};
	adList[4] = {2};
	adList[5] = {};
	adList[6] = {};
	
	depth(adList, 1);
	
}
