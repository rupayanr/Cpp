#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int>
#define vvb vector<vector<bool>>
#define vb vector<bool>

using namespace std;

void floodFill(vvi &maze, int row, int col, string path, vvb &visited){
	
	// Base Case 
	if( row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || maze[row][col] == 1 || visited[row][col] ){
		return;
	}
	
	if( row == maze.size() - 1 && col == maze[0].size() - 1 ){
		cout << path << endl;
		return;
	}

	// A person in a cell can move in 4 directions 
	// Keep a history fo the moves
	
	visited[row][col] = true;
	floodFill(maze, row+1, col, path+"d", visited);
	floodFill(maze, row-1, col, path+"t", visited);
	floodFill(maze, row, col-1, path+"l", visited);
	floodFill(maze, row, col+1, path+"r", visited);
	visited[row][col] = false;
	
	
}

int main(){
	int n,m;
	cin >> n >> m;
	
	vvi maze(n, vi(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> maze[i][j];
		}
	}
	
	vvb visited(n,vb(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			 visited[i][j] = false;
		}
	}	
	
	floodFill(maze, 0, 0, "", visited);
	
}
