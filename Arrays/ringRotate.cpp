#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int> 
#define pb push_back
using namespace std;

vi rotate(vi &a,int r){
	int n = a.size();
	vi aux(n);
	
	if(r < 0){
		
		r = abs(r);
		
		while(r >= n){
			r = r % n;
		}
	
		for(int i=0; i<n; i++){
			aux[i] = a[(i+r) % n];
		}
	}
	
	else{
		while(r >= n){
			r = r % n;
		}
	
		for(int i=0; i<n; i++){
			aux[i] = a[(i+n-r) % n];
		}
	}
	
	
	for(int i=0; i<n; i++){
		a[i] = aux[i];
	}
	
	return a;
}


void display(vi &a){
	for(auto num: a){
		cout << num << " ";
	}
	cout << endl;
}

void display(vvi &a){
	for(auto vec: a){
		for (auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
}




void ringRotate(vvi &a, int s, int r){
	
	// Define minr,c and maxr,c
	int minr = -1, maxr = a.size(), minc = -1, maxc = a[0].size(), count = 0, k=0;
	
	minr += s;
	maxr -= s;
	minc += s;
	maxc -= s;
	
	
	int len = maxc - minc; 

	int bre = maxr - minr;

	int peri = 2*(len + bre);
	
	vi rot(peri);
	
	int total = peri;
	
	while(count < total){
		
		// left Wall 
		for(int i=minr, j=minc; i <= maxr && count < total; i++){
			
			rot[k] = a[i][j];
			k++;
			count++;
		}
		minc++;
		
		
		// bottom wall 
		
		for(int j = minc, i=maxr; j<= maxc && count < total ; j++){
			
			rot[k] = a[i][j];
			k++;
			count++;
		}
		maxr--;
		
		// right wall 
		
		for(int i=maxr, j=maxc; i >= minr && count < total; i--){
			
			rot[k] = a[i][j];
			k++;
			count++;
		}
		maxc--;
		
		// top wall
		for(int j=maxc, i=minr; j>=minc && count < total; j--){
			
			rot[k] = a[i][j];
			k++;
			count++;
		}
		minr++;

	} 

	vi res = rotate(rot, r);

	minr = -1, maxr = a.size(), minc = -1, maxc = a[0].size(), count = 0, k=0;
	
	minr += s;
	maxr -= s;
	minc += s;
	maxc -= s;
	
	while(count < total && k < peri){
		
		// left Wall 
		for(int i=minr, j=minc; i<=maxr && count < total; i++){
		
			a[i][j] = res[k];
			k++;
			count++;
		}
		minc++;
		
		// bottom wall 
		
		for(int j = minc, i=maxr ; j<= maxc && count < total; j++){
		
			a[i][j] = res[k];
			k++;
			count++;
		}
		maxr--;
		
		// right wall 
		
		for(int i=maxr, j=maxc; i>= minr  && count < total; i--){
		
			a[i][j] = res[k];
			k++;
			count++;
		}
		maxc--;
		
		
		// top wall
		for(int j=maxc, i=minr; j>=minc  && count < total; j--){
			a[i][j] = res[k];
			k++;
			count++;
		}
		maxr++;
		
	}
	
	

}

int main(){
	
	int n,m; 
	
	cin >> n >> m;
	
	vvi nums(n,vi(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
			cin >> nums[i][j];
		}
	}
	
	int s, r;
	cin >> s >> r;

	ringRotate(nums,s,r);
	cout << endl;
	display(nums);
	
	
	
}
