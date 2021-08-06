#include<bits/stdc++.h>
using namespace std; 

void display(string s){
	for(char ch: s){
		cout << ch;
	}
	cout << endl;
}

void asciidiff(string s){
	
	int n = s.size();
	string res = s.substr(0,1);
	signed int diff = 0;
	
	for(int i=1; i<n; i++){
		char curr = s[i];
		char prev = s[i-1];

		if(curr != prev){
			diff = (int)curr - (int)prev;
			
			res += to_string(diff);
			res += curr;
			diff = 0;
		}
		
		
	}
	
	display(res);
	
}




int main(){
	string s;
	getline(cin,s);
	asciidiff(s);
}
