#include<bits/stdc++.h>
using namespace std; 

/*
	Problem: 
	Given a string having equations wrapped with brackets 
	if there is duplicacy of number of brackets then cout true i.e there is needless brackets that are not required 	
		
	Solution: 
	1. For each character in the string keep pushing it to the stack till you encounter ')'
	2. After encountering ')' keep popping from the stack till you reach '('
	3. If while popping you encounter '(' at first itself then it is a duplicate, return true.
		Else return false.
	
	i/p 
		1. ( (a+b) + (c+d) ) - > false 
		2. (a+b) + ((c+d)) - > true 
	
	|		|
	|	  	|
	|		|
	|	 	|
	|	)	|
	|	(	| - > true 
	|	+	|
	---------
*/

bool dupBrackets(string s){
	stack<char> stk;
	
	for(char ch : s){

		if(ch != ')'){
			
			stk.push(ch);
		}
		else if (ch == ')'){
			char top = stk.top();
			
			if(top == '('){
				return true;
				
			}
			else{
				
				while(top != '('){
					stk.pop();
					top = stk.top();
				}
			
				stk.pop();
			}
		}
	}
	
	return false;
	
};


int main(){
	string s;
	getline(cin, s);
	
	bool res = dupBrackets(s);
	if(res){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
}
