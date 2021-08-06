#include<bits/stdc++.h>
using namespace std;

void first(unordered_map<char,int> &umap, string &s){
	int n = s.size();
	int idx = 0;
	
	while(idx < n){
		
		char ch = s[idx];
		if(umap.find(ch) != umap.end()){
			
	
			cout << ch;
			idx += umap[ch];
		}	

	}
	cout << endl;
}

void second(unordered_map<char,int> &umap, string &s){
	int idx = 0;
	int n= s.size();
	while(idx < n){
		
		char ch = s[idx];
		if(umap.find(ch) != umap.end()){
			
			if(umap[ch] > 1){
				cout << ch << umap[ch];				
			}
			else{
				cout << ch;
			}

			idx += umap[ch];
		}	

	}
	cout << endl;
	
}


void compress(string s){
	
	int n = s.size();
	unordered_map<char,int> umap;
	
	for(int i=0; i<n; i++){
		
		char ch = s[i];
	
		if(umap.find(ch) != umap.end()){
			umap[ch]++;
		}
		else{
			umap[ch] = 1;	
		}
		
		
	}
	
	first(umap, s);
	second(umap, s);
	

	
	
}

int main(){
	
	string s;
	getline(cin,s);
	compress(s);
}

