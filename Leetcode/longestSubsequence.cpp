#include<bits/stdc++.h>

using namespace std;


int subSequence(string &s){
	
	unordered_map<char,int> map;
	
	int left = 0, right = 0, len = 0;
	int n = s.size();
	
	while(right < n){
		
		if(map.find(s[right]) != map.end()){
			
			left = max(map[s[right]] + 1, left);
		}
		
		map[s[right]] = right;
		len = max(len, right - left + 1);
		right++;
	}
	
	return len;
}

int main(){
	
	string s;
	cout << "Enter input string: ";
	
	getline(cin,s);
	
	
	cout << s<<endl;
	
	int ans = subSequence(s);
	cout << ans << endl;
}
