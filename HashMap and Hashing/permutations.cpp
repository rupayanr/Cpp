#include<bits/stdc++.h>
using namespace std; 


int fact(int n){
	
	int val = 1;
	for(int i=2; i<=n; i++){
		val *= i;
	}
	
	return val;
	
}


void printPermutations(string s){
	
	int n = s.size();
	for(int i=0; i<fact(n); i++){
		vector<char> vec;
		for(auto ch: s){
			vec.push_back(ch);
		}
		int temp = i;
		for(int div = n; div>=1; div--){
			int q = temp / div;
			int r = temp  % div; 
			
			cout << vec[r];
			
			vec.erase(vec.begin() + r);
			
			temp = q;
		}
		
		cout << endl;
		
	}
	
	
}	
	
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
	string s;
	getline(cin,s);
	//printPermutationsRec(s,"");
	
	printPermutations(s);
	
}
