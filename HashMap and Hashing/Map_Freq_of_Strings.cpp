/* Given N strings print unique strings in lexographical order
with their frequency */

#include <bits/stdc++.h>

using namespace std;

int main(){
	// Use unordered to save time
	map<string, int> m;
	
	int t;
	cin >> t; 	
	while(t--){
		string s;
		cin >> s;
		
		m[s]++;
	}
	
	for(auto &pr:m){
		cout << pr.first << " " << pr.second << endl;
	}
	
}
