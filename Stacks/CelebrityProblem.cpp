#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int>
using namespace std;

/*
	Problem: There are n people in a party 
	You are given a matrix of '0's and '1's where party[i][j] = 1 shows that ith person knows jth person
	and 0 shows that they don't know each other 
	
	Definition of a celebrity: Celebrity is known by everyone but knows noone.
	
	so say 2 is a celeb
		1 2 3 
	1 [ x 1 1 ]
	2 [	0 x 0 ]
	3 [	0 1	x ]
	
	Intuition: 
	1) First put each person into a stack 
		
		|       |
		|		|  -> POP 2 elements from the stack
		|	3	|  -> 3 2 
		|	2	|  -> Check relationship b/w popped elements, say party[2][3] is 0 i.e 2 doesn't know 3 	
		|   1	|  -> So we push 2 back to the stack
		---------  -> Then repeat from 1
					-> POP 2 1, say party[1][2] = 1 1 knows 2 so push 2 back 

	Now 2 is a potential celebrity 
	To confirm we run a for loop and check row of 2 and col of 2 while ignoring j=2 and if rows is of 0 and cols is of 1 then 
	2 is a confirmed celebrity.  


*/	

//void findCelebRec(vvi party)


int findCelebrity(vvi &party){
	
	int n = party.size();
	stack<int> stk;
	
	
	for(int i = 0; i<n; i++){
		stk.push(i);
	}
	
	while(stk.size() > 1){
		
		int j = stk.top();
		stk.pop();
		int i = stk.top();
		stk.pop();
		
		if(party[i][j]){
			stk.push(j);
		}else{
			stk.push(i);
		}
		
	}
	
	
	if(stk.empty()){
		return -1;
	}
	
	int pot = stk.top();
	
	
	for(int i = 0; i<n;i++){
		
		if(i != pot){
			if(party[pot][i] == 1 || party[i][pot] == 0 ){
				return -1;
			}
		}
	}
	
	return pot;
	
	
		
}


int main(){
	int n;
	cin >> n;
	
	vvi party(n, vi(n));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> party[i][j];
		}
	} 
	

	
	
	int res = findCelebrity(party);
	if(res != -1){
		cout << res << endl;
	}
	else{
		cout << "none"<<endl;
	}
	
	
}


