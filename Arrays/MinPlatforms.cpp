#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

/*

	Problem: Find min num of platforms required for stationing trains with given arrival and departure times
	Rules : 
			1) Trains come on the same day and leave on the same day
			2) Arrival of a train can be same a departure of another 
			
	arr[] = { 900 800 1400 945 1200 } 
	dep[] = { 1125 945 1200 1010 1145 } 
	
	We can say that max number of trains at one particular time is equal to minimum number of platforms required 
	 
*/

void display(vi vec){
	for(auto el: vec){
		cout << el << " ";
	}
	cout << endl;
}


void getMinPlatforms(vi arr, vi dep){
	
	// Sort the arrival and departures so that we have information on the earliest arrival and departures
	sort(arr.begin(),arr.end());
	sort(dep.begin(),dep.end());
	display(arr);
	display(dep);
	// Using two pointer technique
	int i=0, j=0;
	
	// Init two vars MaxTrains and Platforms
	
	int maxTrains = 0;
	int platform = 0;
	
	while(i < arr.size() && j < dep.size()){
		
		if( arr[i] <= dep[j] ){
			maxTrains++;
			i++;
		}
		else{
			maxTrains--;
			j++;
		}
		platform = max(platform, maxTrains);
		
	}
	
	cout << platform << endl;
	
	
}

int main(){
	int n; 
	cin >> n;
	vi arr(n);
	vi dep(n);

	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}	
	
	for(int i = 0; i<n; i++){
		cin >> dep[i];
	}	
	
	getMinPlatforms(arr,dep);
	
	
}
