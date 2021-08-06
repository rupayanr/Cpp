#include<bits/stdc++.h>

using namespace std;

string compressOne(string s){
	// Only print the characters
	int n = s.size();
	string res = s.substr(0,1);
	
	for(int i=1; i<n; i++){
		// If curr != prev add it to string
		char prev = s[i-1];
		char curr = s[i];
		
		if(curr != prev){
			res += curr;
		}
	}
	return res;	
}

void display(string s){
	for(int i=0; i<s.size(); i++){
		cout << s[i];
	}
	cout << endl;
}



string compressTwo(string s){
	
	string res = s.substr(0,1);		
	int count = 1;
	
	for(int i=1; i<s.size(); i++){
		
		char prev = s[i-1];
		char curr = s[i];
		
		if(curr != prev){
			
			if(count > 1){
				string count_str = to_string(count);
				
				res += count_str;
				count = 1;	
			}
			res += curr;
			
		}
		else{
			count++;
		}	
	}
	
	if(count > 1){
		string count_str = to_string(count);
		res += count_str;
	}
	
	return res;

}

int main(){
	
	string s;
	getline(cin,s);
	string one = compressOne(s);
	display(one);
	
	string two = compressTwo(s);
	display(two);
	
}
