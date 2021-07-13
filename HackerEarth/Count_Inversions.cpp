#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define vi vector<int>
#define f(o,i) for(int i=0; i<n;i++)

using namespace std;

ll int _mergeSort(int arr[], int temp[], int left, int mid, int right);
ll int merge(int arr[], int temp[], int left, int mid, int right);


long long int merge(int arr[], int temp[],int left,int mid,int right){
	
	int count = 0;
	int i =left,j=mid,k=left;
	
	while((i <= mid - 1) && (j <= right)){
		
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			count += mid - i;
			temp[k++] = arr[j++];
		}
	}
	
	while(i <= mid -1){
		temp[k++] = arr[i++];
	}
	
	while(j <= right){
		temp[k++] = arr[j++];
	}
	
	for(int i=left; i<=right; i++){
		arr[i] = temp[i];
	}
	
	return count;
	
}



long long int _mergeSort(int arr[], int temp[],int left, int right){
	
	int mid, count=0;
	if(right > left){
		
		mid = (right + left)/2;
		
		count += _mergeSort(arr,temp,left,mid);
		count += _mergeSort(arr,temp,mid+1,right);
		
		
		count += merge(arr,temp,left,mid+1,right);
		
	}
	
	return count;
}


int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n], temp[n];
		
		f(o,i){
			cin >> arr[i];
		}
		
		int count = _mergeSort(arr,temp,0,n-1);
		cout << count<<endl;
	}
	
}
