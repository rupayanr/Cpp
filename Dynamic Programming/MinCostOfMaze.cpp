#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

/* 
	Problem: You are given a n*m matrix with each cell representing a cost 
	
	You are to reach the last cell with minimum cost and only direction you can move are vertical or horizontal
	
		[ 0 3 4 2 1 ]     [  13 10 6 4   ]
		[ 1 4 5 7 1 ]  -> [  8 11 10 9 3 ]
		[ 0 2 3 0 1 ]	  [  7 7 5 2 2   ]  		
		[ 3 4 1 2 1	]     [ 11 8 4 3 1   ]

		* Cell represents the min cost to reach destination if starting from that cell 
		
		& Min of (vertical cost, horizontal cost) + cost of the cell 
		
		dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + maze[i][j]
		
*/	

void display(vvi &mat){
	for(auto vec: mat){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}


void getMinCost(vvi &maze){
	
	int n = maze.size();
	int m = maze[0].size();
	
	vvi dp(n,vi(m,0));
	
	// Filling the cost of the destination cell 
	
	dp[n-1][m-1] = maze[n-1][m-1];
	
	// Filling values for bottom row 
	
	for(int i=n-1, j=m-2; j>=0; j--){
		dp[i][j] = dp[i][j+1] + maze[i][j];
	}
	
	// Filling values for last col
	
	for(int j=m-1, i=n-2; i>=0; i--){
		dp[i][j] = dp[i+1][j] + maze[i][j];
	}
	
	// Filling the values for rest of the dp 
	
	for(int i=n-2; i>=0; i--){
		for(int j=m-2; j>=0; j--){
			
			dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + maze[i][j];
		}
	}

	cout << dp[0][0] << endl;
	
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vvi maze(n, vi(m,0));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
			cin >> maze[i][j];
		}
	}

	getMinCost(maze);
	
}
