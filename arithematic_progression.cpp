/*
// Sample code to perform I/O:
*/
#include <iostream>
#include <cstdlib>
using namespace std;
 
int minTime(int a, int b, int c){
 
	int res = abs(2*b - (a+c));
	if(res % 2 == 0){
		res = res/2;
	}
	else{
		res += 1;
		res = res/2;
	}
	return res;
	// Calculate min time for abc to be in AP
	
}
 
 
 
int main() {
	int num;
	cin >> num;
	int result; 
	while(num--){
		int a,b,c;
		cin >> a >> b >> c;
		result = minTime(a,b,c);
		cout << result << endl;
	}	
}
