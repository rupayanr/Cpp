#include<bits/stdc++.h>

using namespace std;

int saddlePoint(vector<vector<int>> &a){
	
	int n = a.size();
	int m = a[0].size();
	
	for(int i=0; i<n; i++){
		
		int saddle = INT_MAX;
		int col_idx = 0;
		
		for(int j = 0; j<m; j++){
			
			if(a[i][j] < saddle){
				saddle = a[i][j];
				col_idx = j;
			}
		}
		int k;
		for(k=0; k<n; k++){
			
			if(saddle < a[k][col_idx]){
				break;
			}
		}
		
		if(k == n){
			return saddle;
		}
		
	}
	
	return 0;
	
}

int main(){
	int n;
	cin >> n;
	
	vector<vector<int>> a(n, vector<int>(n));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
		
	}
	
	int res = saddlePoint(a);
	cout << res << endl;
	
}
