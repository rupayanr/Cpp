#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int d, int t1, int t2, int t3){
	/*
		Disks D to be moved from t1 to t2 using t3
	*/
	
	// Base Case
	if(d == 0){
		return;
	}
	
	// Faith : towerOfHanoi(d-1, t1, t3, t2) i.e this function will transfer d-1 disks to tower 3 complying to the rules
	towerOfHanoi(d-1,t1,t3,t2);
	cout << d << "[" << t1 << " -> " << t2 << "]"<<endl;
	towerOfHanoi(d-1, t3, t2, t1);
	
}

int main(){
	int n, t1, t2, t3;
	cin >> n >> t1 >> t2 >> t3;
	towerOfHanoi(n,t1,t2,t3);
}	
