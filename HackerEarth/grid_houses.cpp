#include <bits/stdc++.h>
#define endl "\n"
#define f(i,n) for(int i=0; i<n; i++)


using namespace std;


int main(){
	
	int n, flag;
	string grid;
	cin >> n;

	f(i,n){
		cin >> grid[i];
	}
	
	f(i,n-1){
		if(grid[i] == 'H' && grid[i+1] == 'H'){
			flag = 0;
			break;	
		}
		else{
			flag = 1;
		}
	}
	
	if(flag == 1 /* && grid[0] == 'H'*/){
		
		f(i,n){
		if(grid[i] == '.'){
				grid[i] = 'B';
			}
		}	
		cout << "YES" << endl;
		f(i,n){
			cout << grid[i];
		}
	}
	else if(flag == 0){
		cout << "NO";
	}

	
	
	
	

	
}
