/* To calucalte maximum borders of the shape formed by # 
@author : rupayanr */

#include <bits/stdc++.h>

using namespace std;

// Rows, cols
int n,m;
int result;
char s[1001][1001];
char a[1001][1001];


int calBorders(){

    int res = 0;
    
    for(int i=0; i < n; i++){
        
        int count = 0;
        for(int j=0; j < m; j++){

            if(a[i][j] == '#'){

                a[i][j] = '@';
                count += 1;
                if(i+1 < n && a[i+1][j] == '#'){

                    a[i+1][j] = '@';
                    
                }
            }

            else if(a[i][j] == '@'){
                if(i+1 < n && a[i+1][j] == '#'){

                    a[i+1][j] = '@';
                }

                res = max(res,count);
                count = 0;

            }

            else if(a[i][j] == '.'){

                res = max(res,count);
                count = 0;
            }
        }
        res = max(res,count);
    }

    return res;


}


int main(){

    // Number of testcases
    int t;
    cin >> t;

    while(t--){
        
        cin >> n >> m;
        
        /* Case 1
        2 15
        .....####......
        .....#.........
        */
        for(int i=0; i<n; i++){
            
            for (int j = 0; j < m; j++)
            {
                cin >> s[i][j];
            }
            
        }

		for(int i = 0; i<n; i++){

            for(int j = 0; j<m; j++){
                a[i][j] = s[i][j];
            } 
        }

        result = calBorders();

        cout << result << endl;
			

		//cout<<res<<endl;
    }

    
}