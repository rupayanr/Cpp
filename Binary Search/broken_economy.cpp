#include<bits/stdc++.h>
using namespace std;

void findDenoms(vector<int> &denoms, int target){
	
	int left = 0;
	int right = denoms.size() - 1;
	
	int ans = 0;
	
	while(right - left > 1){
		
		int mid = left + (right - left)/2;
	
		if(target < denoms[mid]){
			right = mid;
		}	
		else if(target > denoms[mid]){
			left = mid;
		}
		else{
			ans = denoms[mid];
			break;
		}
		
	}
	
	
	if(ans == target){
		cout << ans<<endl;
	}
	else{
		cout << denoms[right] << endl;
		cout << denoms[left]<<endl;
	}
	
}

int main(){
	int n,target;
	cin >> n;
	
	vector<int> denoms(n);
	
	for(int i=0; i<n; i++){
		cin >> denoms[i];
	}
	
	cin >> target;
	
	findDenoms(denoms, target);
}
