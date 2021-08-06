#include<bits/stdc++.h>
using namespace std;

void display(string &s){
	for(int i=0; i<s.size(); i++){
		cout << s[i];
	}
	cout << endl;
}

void toggleCase(string s){
	
	string res="";

	for(int i=0; i<s.size(); i++){
		char ch = s[i];
		
		if(isupper(ch)){
			res += tolower(ch);
		}else{
			res += toupper(ch);
		}
	}
	
	display(res);
}

int main(){
	string s;
	getline(cin,s);
	toggleCase(s);
}
