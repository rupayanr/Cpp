#include<bits/stdc++.h>

using namespace std;

vector<string> getSubSets(string s){
	
	
	// Base Case 
	if(s.size() == 0){
		vector<string> vec;
		vec.push_back("");
		return vec;
	}
	

	char ch = s.at(0);
	string substr = s.substr(1);
	
	vector<string> recr = getSubSets(substr);
	
	vector<string> myres;
	
	for(auto str: recr){
		myres.push_back("" + str);
		myres.push_back(ch + str);
	}
	
	return myres;
	
}


int main(){
	string s;
	getline(cin,s);
	vector<string> res = getSubSets(s);
	
	for(auto str: res){
		cout << str << " ";
	}
	
}
