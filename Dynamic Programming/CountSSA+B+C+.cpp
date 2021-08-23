#include<bits/stdc++.h>
using namespace std;

/*
	Problem: Given string of the nature a+b+c+ find out the number of possible substr of this nature 
			0   a    b   c   a'  b'   c'
	
	a+      0   1    1   1   3   3    3
	
	a+b+    0   0    1   1   1   5    5 
 
    a+b+c+  0   0    0   1   1   1    7

	for A = 2*A + 1 -> Because A' can choose to join prev A's or not plus it can start its own string A'+
	for B = 2*B + A -> Because B' will join prev A's and can choose from prev B's 
	for C = 2*c + B -> Same as above 

*/


void getSS(string s){
	
	int n = s.size();
	int a = 0;
	int ab = 0; 
	int abc = 0;
	
	for(int i=0; i<n; i++){
		if(s[i] == 'a'){
			a = 2*a +1;
		}
		else if(s[i] == 'b'){
			ab = 2*ab + a;
		}
		else if(s[i] == 'c'){
			abc = 2*abc + ab;
		}
	}
	
	cout << abc << endl;
	
}

int main(){
	string s;
	getline(cin,s);
	getSS(s);
}
