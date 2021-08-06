#include<bits/stdc++.h>
using namespace std; 



void printPermutationsRec(string s, string res){
	
	
	if(s.size() == 0){
		cout << res << endl;
		return;
	}
	
	for(int i=0; i<s.size(); i++){
		
		char ch = s[i];
		
		string left = s.substr(0,i);
		string right = s.substr(i+1);
		
		printPermutationsRec(left+right, res + ch);
	}
	
	
}

int main(){
	
}
