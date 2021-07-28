#include<bits/stdc++.h>

using namespace std; 


bool isPalindrome(long long int x){
	
    if(x < 0 || (x%10 == 0 && x != 0)){
        return false;
    }
    
    long long int ans = 0;
    while(x > ans){

        ans = ans * 10 + x % 10 ;

        x = x / 10; 
        cout << x << endl;
    }

    return (x==ans)||(x == ans/10);
}





int main(){
	
	long long int x;
	cin>>x;

	if(isPalindrome(x)){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}
