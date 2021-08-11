#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int> 


using namespace std;

void display(vvi chess){
	for(auto row: chess){
		for(auto el: row){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void knightsTour(vvi &chess, int r, int c, int move){
	
	// Base Case 
	if(r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] > 0){
		return;
	}
	
	// Result Case 
	if(move == chess.size() * chess.size()){
		chess[r][c] = move;
		display(chess);
		chess[r][c] = 0;
		return;
	}
	
	
	
	chess[r][c] = move;
	knightsTour(chess, r-2, c+1, move + 1);
	knightsTour(chess, r-1, c+2, move + 1);
	knightsTour(chess, r+1, c+2, move + 1);
	knightsTour(chess, r+2, c+1, move + 1);
	knightsTour(chess, r+2, c-1, move + 1);
	knightsTour(chess, r+1, c-2, move + 1);
	knightsTour(chess, r-1, c-2, move + 1);
	knightsTour(chess, r-2, c-1, move + 1);
	chess[r][c] = 0;

}

int main(){
	int n, r, c;
	cin >> n >> r >> c;
	
	vvi chess(n,vi(n));
	
	knightsTour(chess,r,c,1);
}
