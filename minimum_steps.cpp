#include <bits\stdc++.h>

using namespace std;

int calSteps(int k, int m, int n){
    int temp = 0;
    int cnt = 0;
    // To convert integer k to m by only 3 operations

    // Check if m is greater than k
    if(m > k){
        temp = k;
        cnt = 0;
        // Making temp greater than m so that 1 or 2 can be subtracted accordingly
        while(m > temp){
            temp *= n;
            cnt += 1;
        }

        // cout << "Temp = " << temp << "\n";
        // cout << "Count = " << cnt << "\n";

        while(temp != m){
            cout << "In while" << "\n";
            if(m == temp){
                break;
            }
             
            else if((temp - m) % 2 == 0){
                temp -= 2;
                cnt += 1;

            }
            else if ((temp - m) % 2 != 0){
                temp -= 1;
                cnt += 1;


            }

            // cout << "Temp = " << temp << "\n";
            // cout << "Count = " << cnt << "\n";
        }
        
    }
    
    if(m < k){
        temp = k;
        cnt = 0;
        // cout << "Temp = " << temp << "\n";
        // cout << "Count = " << cnt << "\n";
        while(temp != m){

            if((temp - m) % 2 == 0){
                temp -= 2;
                cnt += 1;

            }
            else{
                temp -= 1;
                cnt += 1;
            }
        //    cout << "Temp = " << temp << "\n";
        //    cout << "Count = " << cnt << "\n";

        }

    }
    return cnt;

}


int main(){

    int t;
    cin >> t;
    int result = 0;
    while(t--){

        int k,m,n;
        cin >> k >> m >> n;
        result = calSteps(k,m,n);
        cout << result << endl;
    }

    
    


}