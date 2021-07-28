#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> matrixMul(vector<vector<int>> m1, vector<vector<int>> m2){
	
	vector<vector<int>> res(m1.size(), vector<int>(m2[0].size()));
	
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m2[0].size(); j++){
			res[i][j] = 0;
			for(int k=0; k<m2[0].size(); k++){
				
				res[i][j] += m1[i][k] + m2[k][j]; 
			}
		}
	}
	
	return res;
	
}

vector<vector<int>> makeTwoDArray(int rows, int cols){
	
	vector<vector<int>> vec;
	
	for(int i=0; i<rows; i++){
		
		vector<int> v;
		
		for(int j=0; j<cols; j++){
			
			int x;
			cin >> x;
			v.push_back(x);
		}
		
		vec.push_back(v);
	}
	
	return vec;
	
}

void display(vector<vector<int>> nums){
	
	for(auto row: nums){
		for(auto el : row){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	
	int n,m; 
	
	cin >> n >> m;
	
	vector<vector<int>> m1 = makeTwoDArray(n,m);

	
	int k,l; 
	cin >> k >> l;
	
	vector<vector<int>> m2 = makeTwoDArray(k,l);

	
	if(m != k){
		cout << "Invalid input"<<endl;
	}
	else{
		vector<vector<int>> res = matrixMul(m1,m2);
		display(res);	
	}
	
	

}
