#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string>

using namespace std;

void check_str(string str){

    string upp_vow = "AEIOU";
    string low_vow = "aeiou";
    int countup = 0;
    int countlow = 0;

    // Looping through input string
    for(int i=0; i<str.length();i++){

        // Checking for uppercase
        for(int j=0; j<upp_vow.length();j++){
            
            if(str[i] == upp_vow[j]){
                countup++;
                break;
            }
        }
        // Checking for lowercase
        for(int k=0; k<low_vow.length(); k++){

            if(str[i] == low_vow[k]){
                countlow++;
                break;
            } 

        }

    }

    if(countup == 5 || countlow == 5){

        cout << "lovely string" << endl;
    }
    else{
        
        cout << "ugly string" << endl;
    }


}


int main(){
    int t;
    cin >> t;


    while(t--){
        string s; 
        cin >> s;
        check_str(s);
    }
}