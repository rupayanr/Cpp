#include <bits/stdc++.h>
using namespace std;

void display(stack<char> stk){
		while(stk.top() != -1){
		cout << stk.top() <<endl;
		stk.pop();
	}
}



int main(){
	
	stack <char> stk;
	long double res=0,open=0,close=0;
	string s; // ) ( ) ( ) (
	getline(cin,s);
	
	for(long i=0; i < s.size(); i++){
		
		if(s[i] == ')' && !stk.empty()){
			
			if(stk.top() == '('){
				stk.pop();
				
			}
			else{
				stk.push(s[i]);
				
			}
		}
		else{
			stk.push(s[i]);
		}
	}
	
	while(!stk.empty()){
		
		if(stk.top() == '('){
			open++;
		}
		else if(stk.top() == ')'){
			close++;
		}
		
		stk.pop();
	}
	
	cout << open << close << endl;
	res = ceil(open/2) + ceil(close/2);
	
	cout << res << endl;
	
	
	//cout << res << endl;
	

}
