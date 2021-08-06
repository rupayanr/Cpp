#include<bits/stdc++.h>
using namespace std;

void decrease(int n){

	if(n == 1){
		cout << n << " ";
		return;
	}

	cout << n << " ";	
	decrease(n-1);
}

int main(){
	decrease(5);
}
