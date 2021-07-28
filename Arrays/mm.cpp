#include<iostream>
using namespace std;

int main(){
    
    int r1,c1;
    cin >> r1 >> c1;
    
    int first[r1][c1];
    
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            
            cin >> first[i][j];
        }
    }
    
    int r2,c2;
    cin >> r2 >> c2;
    
    int second[r2][c2];
    
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            
            cin >> second[i][j];
        }
    }
    
	int res[r1][c2];
        
    for(int i=0; i<r1; i++){
	    for(int j=0; j<c2; j++){
		    res[i][j] = 0;
        }
    }
    
    
    if(c1 != r2){
        cout << "Invalid input" <<endl;
        return 0;
    }
    
        

        
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
           for(int k=0; k<c1; k++){
           	
               res[i][j] += first[i][k] * second[k][j];
		   
		   }
        }
    }
    
    
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            cout << res[i][j] << " "; 
        }
        cout << endl;
    }
    
    
        
    
}
