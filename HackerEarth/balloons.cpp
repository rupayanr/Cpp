#include <bits/stdc++.h>
#define f(i,n) for(int i=0; i < n; i++)
#define fo(i,v) for(auto i: v)
#define pb push_back 

using namespace std;

int main(){
	
	int t;
	cin >> t;
	while(t--){
		
		int g=0, p=0,n=0, mincost=0, maxcost=0,maxcnt=0,mincnt=0, g_cnt = 0, p_cnt=0;
		cin >> g >> p;
		cin >> n;
		
		mincost = min(g,p);
		maxcost = max(g,p);
	

		vector<pair<int,int>> v;
		
		f(i,n){
			int x,y;
			cin >> x >> y;
			v.pb(make_pair(x,y));
		}
		
		fo(i,v){
			
			if(i.first == 1){
				g_cnt += 1;
			}
			
			if(i.second == 1){
				p_cnt += 1;
			}
			
		}
		
		mincnt = min(g_cnt,p_cnt);
		maxcnt = max(g_cnt,p_cnt);
		cout << (maxcnt * mincost) +(mincnt * maxcost) << endl;
		
		
		
	}
}

