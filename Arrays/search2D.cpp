#include<bits/stdc++.h>
#define vvi vector<vector<int>> 

using namespace std;


bool search2D(vvi &a, int target){
	
	/* 
	
		Naiive approach would be to traverse the entire array 
		and find it 
		But we can use the property that the array is sorted 
		
		One way is that we can find is by doing a binary search on each row 
		but we can avoid doing that too by doing checking if the last element is >= target 
		then we do a binary search on that row or we move to the next row
		
		Second way could by using the prop of the matrix that it is sorted so 
		we can use an auxillary space that can be filled with the matrix elements and binary search 
		can be used 
		
		Third and the optimal way is to not use extra space and calculate the index using 
		a trick i.e ith index in array = index in array / m  jth is index % m 
	
	*/
	int n = a.size();
	int m = a[0].size();
	
	int lo = 0; 
	int hi = n*m;
	
	while(lo <= hi){
		int mid = lo + (hi - lo)/2;
		int i = mid / n;
		int j = mid % m;
		
		if( target > a[i][j]){
			lo = mid + 1;
		}
		else if(target < a[i][j]){
			hi = mid - 1;
		}
		else{
			cout << i << endl;
			cout << j << endl;
			return true;
		}
	}
	
	return false;
	
	
	
	
	
	
}

int main(){
	int n;
	cin >> n; 
	
	vector<vector<int>> a(n,vector<int>(n));
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> a[i][j];
		}
	}
	int x;
	cin >> x;
	if(!search2D(a,x)){
		cout << "Not Found"<<endl;
	}
	
	
}
