#include <bits/stdc++.h>
using namespace std; 

vector<int> diff(vector<int> a, vector<int> b){
	
	int c = 0;
	vector<int> diff(b.size()); 
	
	int i = a.size() - 1;
	int j = b.size() - 1;
	int k = b.size() - 1;	
	
	while(k >= 0){
		int d = 0;
		
		int ai = i >= 0? a[i] : 0; 
		
		if(b[j] + c >= ai){
			d = b[j] + c - ai;
			c = 0;
		}
		else{
			d = b[j] + c + 10 - ai;
			c = -1;			
		}
		
		diff[k] = d;
		i--;
		j--;
		k--;
		
	}
	
	int idx = 0;
	
	while(idx < diff.size()){
		if(diff[idx] == 0){
			idx++;
		}
		else{
			break;
		}
	}
	
	while(idx < diff.size()){
		cout << diff[idx] << endl;
		idx++;
	}
	
	return diff;
	
}

int main(){
	int n1, n2;
	cin >> n1;
	vector<int> a(n1);
	
	for(int i=0; i<n1; i++){
		cin >> a[i];
	}
	
	cin >> n2;
	vector<int> b(n2);
	
	for(int i=0; i<n2; i++){
		cin >> b[i];
	}
	
	vector<int> res = diff(a,b);
	
}
