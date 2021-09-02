#include<bits/stdc++.h>
using namespace std; 

/*
	Problem: Check if the paranthesis are balanced i.e num opening brackets are equal to num of closed brackets 
	Solution: 
		1) We use a stack to keep track of the paranthesis and only push paranthesis into it 
		2) If we encounter a closing tag then we check on top of the stack if it matches with its counterpart 
			2.a) If it does we pop its counter part 
		3) If the stack is empty in the end then we it is BALANCED
			Else its is not balanced.
*/

bool balancedParanthesis(string &s){
	
	stack<char> stk; // [{
	// [(a + b) + {(c + d) * (e / f)}])
	for(char ch : s){ 
		// Only including paranthesis 
		if(ch == ')' || ch == '(' || ch == '{' || ch == '}' || ch == '[' || ch == ']' ){
			
			if(ch == ')' || ch == '}' || ch == ']'){
				
				if(stk.empty()){
					//cout << "Syack is empty, pushing:  " << ch << endl;
					stk.push(ch);
				}
				else{
					char top = stk.top();
				
					if(top == '(' && ch == ')'){
					//	cout << "Popping: " << top << endl;
						stk.pop();
					}
					else if(top == '{' && ch == '}'){
					//	cout << "Popping: " << top << endl;
						stk.pop();
					}
					else if(top == '[' && ch == ']'){
					//	cout << "Popping: " << top << endl;
						stk.pop();
					}
					else{
					//	cout << "Pushing: " << ch << endl; 
						stk.push(ch);
					}					
				}

			}
			else{
				cout << "Pushing: " << ch << endl;
				stk.push(ch);
			}
		}
	}

	if(stk.empty()){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string s;
	getline(cin, s);
	
	bool res = balancedParanthesis(s);
	
	if(res){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	
}
