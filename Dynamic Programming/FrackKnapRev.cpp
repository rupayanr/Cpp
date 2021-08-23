#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vI vector<Item*>
using namespace std;

class Item{
	
	public:
		int weight;
		int value;

};


bool comp(Item *a, Item *b){
	double ra = double(a->weight / double(a->value));
	double rb = double(b->weight / double(b->value));
	return ra > rb;
}

void frackKnap(vI &items, int cap){
	
	sort(items.begin(), items.end(), comp);
	
	int currWt = 0;
	double currVal = 0;
	
	
	for(auto item: items){
		if(currWt + item->weight <= cap){
			currWt += item->weight; 
			currVal += item->value;
		}
		else{
			int rem = cap - currWt;
			currVal += ( double(item->weight) / double(item->value) ) * rem;
			break;
		}
	}
	
	cout << setprecision(2) << currVal <<endl;
	
}

int main(){
	
	int n;
	cin >> n;
	
	vi wts(n);
	vi vals(n);
	
	vI arr;
	
	for(int i=0; i<n; i++){
		cin >> wts[i];
	}
	
	for(int i=0; i<n; i++){
		cin >> vals[i];
	}
	
	int cap;
	cin >> cap;
	
	for(int i=0; i<n; i++){
		
		
		Item *obj = new Item;
		obj->value = vals[i];
		obj->weight = wts[i];
		
		arr.push_back(obj);
	}
	
	frackKnap(arr,cap);
	
}


