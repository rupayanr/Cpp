 #include <bits/stdc++.h>
#define f(o,n) for(int i=0;i<n;i++)
#define pb push_back

using namespace std;

void display(vector<int> vec){
	for(auto el:vec){
		cout << el << " ";
	}
	cout << endl;
}


int main(){
	
	int t;
	
	cin >> t;
	while(t--){
		
		int n,k;
		
		cin >> n >> k;
		
		vector<int> arr(n);
		vector<int> monk(n); 
		
		f(o,n){
			int x;
			cin >> x; 
			arr[i] = x;
		}
		
		f(o,n){
			monk[(i+k)%n] = arr[i];
		}
		
		display(monk);
		
		
	}
	
	return 0;
	
}
