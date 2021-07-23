#include <bits/stdc++.h>
using namespace std;

int dp[102][102];

/* LEETCODE: 1547 Minimum cost to cut a stick of length N and Cuts array

	Cuts [ 1, 3, 4, 5]
	
	N {0,1,2,3,4,5,6,7}

	Say I start from 1 then 3 then 4 i.e normal order
	
	-> 1 {0,1} {1,2,3,4,5,6,7} Cost = Cost(0,7) = 7
	-> 3 {0,1} {1,2,3} {3,4,5,6,7} Cost = Cost(1,7) = 6
	-> 4 {0,1} {1,2,3} {3,4} {4,5,6,7} Cost(3,7) = 4
	-> 5 {0,1} {1,2,3} {3,4} {4,5} {5,6,7} = Cost(4,7) = 3 // 7+6+4+3 = 21	
 
    But we are tasked with finding the min cost
    We can use brute force and cycle throught the array using a circular queue 
    but better approach would be Recursion + Memoization 
    
    We can infer that Cost(0,n) = Cost(0,7) (N = 7 in this case) = 7-0 + min( Combinations of cuts to (0,7) )
    So that is 
    Cost(0,7) = 7-0 + min{

		Cost(0,1) + Cost(1,7),
		
		Cost(0,3) + Cost(3,7),
		
		Cost(0,4) + Cost(4,7),
		
		Cost(0,5) + Cost(5,7)
	}
	
	
	We can keep a dp[low][high] that stores the min cost b/w low and high for any given combination
	
 */ 


int _minCost(int low, int high, vector<int> &cuts){
	
		// Base Case 
		if(low + 1 == high){
			return 0;
		}
		// Memoization of dp[low][high] to avoid recalculation
		else if(dp[low][high] != -1){
			return dp[low][high];
		}
		else{
			
			// Initializing ans with max int
			int ans = INT_MAX;
			for(int i = low + 1; i < high; i++){ 
			// Starting the loop from low+1 since 1st el will be 0 which is not the cut to be made
				int cost = cuts[high] - cuts[low] + _minCost(low, i, cuts) + _minCost(i,high,cuts);
				ans = min(ans, cost);
			}
			return dp[low][high] = ans;	
		}
		
}


int minCost(int n, vector<int> &cuts){
	
	cuts.push_back(0);
	cuts.push_back(n);
	sort(cuts.begin(), cuts.end());
	memset(dp, -1, sizeof(dp));
	return _minCost(0,cuts.size()-1,cuts);
	
}

int main(){
	
	vector<int> cuts{5,6,1,4,2};
	int n; 
	
	cin >> n;
	
	int ans = minCost(n,cuts);
	cout << ans;
	
	
	
}
