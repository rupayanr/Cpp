#include<bits/stdc++.h>
using namespace std; 

bool isPalindrome(string s){
	
	int i=0;
	int j=s.size()-1;
	while(i <= j){
		
		if(s[i] == s[j]){
			i++;
			j--;
		}
		else{
			return false;
		}
		
	}
	
	return true;
	
}

void printAll(string s){
	// abccbab
	int n = s.size();
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			
			string sub = s.substr(i,j-i+1);
			
			if(isPalindrome(sub)){
				cout << sub << endl;
			}
			
		}
	}
}

int main(){
	string s;
	getline(cin, s);
	printAll(s);
}
