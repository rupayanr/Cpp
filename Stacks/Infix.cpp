#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std;

/*
	To perform infix evaluation on the given expression 

	2 + 3 - ( 5 * 8 + 4/2)
	-37 
	
	We have some rules and assumptions 
	
	1) Precendence of operator + - is same and < * / 
	2) Single digits only 
	3) '(' means calculate this first 
	4) ')' means pop and calc till you reach '('
	4) If you encounter an operator of lower precedence then pop 
	if at the top you have operator precedence >= yourself till either size = 0 or you encounter '(' 
	

	It would be better to create helper functions for operator precedence and operations 
	
	say stacks have 
	
	|	3	|	| 		|
	|	2	|	|	-	| -> This means that while calculating you will pop 2 operands and use 2 - 3 not 3 - 2
	---------    -------
*/ 

int priority(char &ch){

	if(ch == '+'){
		return 1;
	}
	else if(ch == '-'){
		return 1;
	}
	else if(ch == '*'){
		return 2;
	}
	else{
		return 2;
	}

}

int operation(int &v1, int &v2, char &ch){

	if(ch == '+'){
		return v1 + v2;
	}
	else if(ch == '-'){
		return v1 - v2;
	}
	else if(ch == '*'){
		return v1 * v2;
	}
	else{
		return v1/v2;
	}
}


void calcInfix(string exp){
	
	
	// Create 2 stacks one for operand(int) and one for operation(char) 
	stack<int> oprnd;
	stack<char> oprtr;

	// Filling the two stacks 
	for(int i=0; i<exp.size(); i++){

		char ch = exp[i];
		

		if(isdigit(ch)){
			int val = ch - '0';
			
			oprnd.push(val);
		}
		else if(ch == '('){
			oprtr.push(ch);
		}
		else if(ch == ')'){
			// pop till ( 

			while(oprtr.top() != '('){
				char op = oprtr.top();
				oprtr.pop();

				int v2 = oprnd.top();
				oprnd.pop();

				int v1 = oprnd.top();
				oprnd.pop();

				int val = operation(v1, v2, op);
				oprnd.push(val);
			}
			// Popping ( tag
			oprtr.pop();
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){

			// Pop till < precedence or size = 0 or (
			// else push
			// Higher priorty operators get processed first 
			
			while(oprtr.size() > 0 && oprtr.top() != '(' && priority(ch) <= priority(oprtr.top()) ){

				char op = oprtr.top();
				oprtr.pop();

				int v2 = oprnd.top();
				oprnd.pop();

				int v1 = oprnd.top();
				oprnd.pop();

				int val = operation(v1, v2, op);
				
				oprnd.push(val);
			}
			// After pre processing prev operators push yours
			oprtr.push(ch);
		}
	}

	while(oprtr.size() > 0){
		char op = oprtr.top();
		oprtr.pop();

		int v2 = oprnd.top();
		oprnd.pop();

		int v1 = oprnd.top();
		oprnd.pop();

		int val = operation(v1, v2, op);
		oprnd.push(val);
	}


	cout << oprnd.top() << endl;
}


int main(){

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif
	   string s;
	   getline(cin ,s);

	   calcInfix(s);


}