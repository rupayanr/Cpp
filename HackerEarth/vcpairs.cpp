/*
// Sample code to perform I/O:
*/

#include <iostream>
using namespace std;

bool isVowel(char s){

    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'){
        return true;
    }
    else{
        return false;
    }

}



int main() {
	int num;
	cin >> num;
        
	while(num--){
        int res = 0;
		int len;
		string test;
		cin >> len >> test;

		for(int i=0; i < len; i++){
            if(!isVowel(test[i]) && isVowel(test[i+1])){
                res++;
            }
        }
		cout << res << endl;

		
	}
}


