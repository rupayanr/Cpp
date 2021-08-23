#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>>
using namespace std;

int getMinCost(vvi &cost){
	int n = cost[0].size(); 
	
	int r = cost[0][0];
	int b = cost[1][0];
	int g = cost[2][0];
	int minC = INT_MAX;
	
	for(int i=1; i<n; i++){
		
		int newR = min(b,g) + cost[0][i];
		int newB = min(r,g) + cost[1][i];
		int newG = min(r,b) + cost[2][i];
		
		r = newR;
		b = newB;
		g = newG;

	}
	
	minC = min(r,b);
	minC = min(minC, g);
	return minC;
	
}

void display(vvi &cost){
	for(auto vec: cost){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
}

int main(){
	int n; 
	cin >> n;
	
	vvi cost(3,vi(n));
	
	for(int j = 0; j<n; j++ ){
		for(int i=0; i<3; i++){
			int color;
			cin >> color;
			cost[i][j] = color;
		}
	}

	
	int res = getMinCost(cost);
	cout << res;
	
}
