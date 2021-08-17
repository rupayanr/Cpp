#include<bits/stdc++.h>
#define vi vector<int> 
#define vpi vector<pair<int,int>>

using namespace std;

static bool comp(pair<int,int> a, pair<int,int> b){
	double r1 = (double)a.second / (double)a.first;
	double r2 = (double)b.second / (double)b.first;
	
	return r1>r2;
}

void fracKnap(vpi &arr, int cap){
	
	sort(arr.begin(), arr.end(), comp);
	
	int currWt = 0; 
	double result = 0;
	
	for(int i=0; i<arr.size(); i++){
		if(currWt + arr[i].first <= cap){
			currWt += arr[i].first; 
			result += arr[i].second;
		}
		else{
			double remWt = cap - currWt;
			result += ((double)arr[i].second / (double)arr[i].first) * remWt;
			break;
		}
	}	
	
	cout << setprecision(2) << result << endl;
}

int main(){
	int n; 
	cin >> n; 
	vi weight(n);
	vi value(n);
	vpi arr(n);
	
	for(int i=0; i<n; i++){
		cin >> value[i];
	}
	
	for(int i=0; i<n; i++){
		cin >> weight[i];
	}
	
	for(int i=0; i<n; i++){
		arr[i].first = weight[i];
		arr[i].second = value[i];
	}
	
	int cap;
	cin >> cap; 
	
	fracKnap(arr,cap);
	
}
