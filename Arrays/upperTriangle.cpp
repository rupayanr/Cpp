#include<bits/stdc++.h>

using namespace std;

void display(vector<vector<int>> &a){
	for(auto vec: a){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void upperTriangle(vector<vector<int>> &a){
	
	int n = a.size();
	int m = a[0].size();
	
	int minc = 0;
	int maxr = n - 1; // 3
	
	int minr = 0;
	int maxc = m - 1; // 3
	
	
	int i=minr, j=minc; // i = 0, j = 0
	
	while(minc <= maxc && maxr >= minr){
		
		// Diagonal Printing
		while(i <= maxr && j <= maxc){
			
			cout << a[i][j] << endl;
			i++;
			j++;
		}
		
		maxr--;
		minc++;
		
		i = minr;
		j = minc;
		
	}
	
}

int main(){
	
	int n; 
	cin >> n; 
	vector<vector<int>> a(n,vector<int>(n));
	
	for(int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	
	display(a);
	upperTriangle(a);
	
}
