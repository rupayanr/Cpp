#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>

/* 
	Problem Statement: 
	You are give an N*N matrix you have to postion N queens in that array such that 
	no one queen can kill the others
	
*/

using namespace std;

bool isQueenSafe(vvi &chess, int row, int col){
	
	// Vertical Safety 
	for(int i = row - 1, j = col; i >=0; i--){
		if(chess[i][j]){
			return false;
		}
	}
	
	// Left Diagonal Safety
	
	for(int i = row - 1, j = col - 1; i>=0 && j>=0; i--, j--){
		if(chess[i][j]){
			return false;
		}
	}
	
	// Right Diagonal 
	
	for(int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++){
		if(chess[i][j]){
			return false;
		}
	}
	
	return true;
	
	
}



void getPositions(vvi &chess, string path, int row){
	
	// First Try to put the queens in the array regardless of safety
	
	// Base Case 
	if(row == chess.size()){
		
		path += ".";
		cout << path << endl;
		return;
	}
	
	
	for(int col=0; col<chess[0].size(); col++){
		
		
		// Check if Queen is safe in the curr pos
		
		if(isQueenSafe(chess,row,col)){
		
			chess[row][col] = 1;
		
			getPositions(chess, path + to_string(row) + "-" + to_string(col) + ",", row+1);
		
			// Backtrack the prev step 
			chess[row][col] = 0;
	
		}
	
	}
	

}


int main(){

int n;
cin >> n;
vvi chess(n,vi(n));

getPositions(chess,"",0);



	
}
