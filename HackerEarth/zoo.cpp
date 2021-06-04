#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string zoo;
	cin >> zoo;
	
	size_t x = zoo.find_last_of("z");
	size_t y = zoo.find_last_of("o"); // - zLast;
	y -= x;
	x += 1;
	
	
	
	if(y == 2*x){
		cout << "Yes";
	}
	else{
		cout<< "No";
	} 
	
	
	
	
}
