#include <iostream>

#include <bits/stdc++.h>


using namespace std;




int minSteps(vector<int> a, vector<int> b, vector<int> minEl)
{

    int count, diff;

	
	// Storing minima of array a in minEle vector
	int min = *min_element(a.begin(),a.end());
	minEl.push_back(min);
	
	
	// To find all the possible minimas we'll subtract the min val with b[i] 
	for(int i=0; i<a.size();i++ ){
		if(a[i] == min){
			while(min > b[i] && b[i]){
				min -= b[i];
				minEl.push_back(min);
			}
			break;
		}
	}
	
	for(int min: minEl){
		count = 0;
		for(int i=0;i<a.size();i++){
			
			if(a[i] == min){
				continue;
			}
			else{
				diff = a[i] - min;
				if(diff%b[i] == 0){
					count += diff/b[i];
				}
				else{
					count = -1;
					break;
				}
			}			
		}
		
		if(count!=-1){
			break;
		}

	}
	
	
    return count;
};

void display(vector<int> vec)
{

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
};

int main()
{

    int n, res;
    
	
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    vector<int> minEl;
	
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
	
    res = minSteps(a, b, minEl);
    cout << res;
    
    
}

