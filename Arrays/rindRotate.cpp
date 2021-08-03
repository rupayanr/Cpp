#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int> 
#define pb push_back
using namespace std;

void rotate(vi &a){
	
}

void display(vvi &a){
	
}

void ringRotate(vvi &a, int s, int r){
	
	// Define minr,c and maxr,c
	int minr = 0, maxr = a.size(), minc = 0, maxc = a[0].size(), count = 0, k=0;
	
	minr += s;
	maxr -= s;
	minc += s;
	maxc -= s;
	
	int len = maxc - minc; 
	int bre = maxr - minr;
	int peri - 2*(len + bre);
	
	vi rot(peri);
	
	int total = peri;
	
	while(count < total && k < peri){
		
		// left Wall 
		for(int i=minr, j=minc; i<=maxr && count < total; i++){
			rot[k] = a[i][j];
			k++;
			count++;
		}
		
		// bottom wall 
		
		for(int j = minc, i=maxr; j<= maxc; j++){
			rot[k] = a[i][j];
			k++;
			count++;
		}
		
		
		
		
		
		
	} 
	
	
	
}

int main(){
	
}
