#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &vec){
	
	for(auto el: vec){
		cout << el << " ";
	}
	cout << endl;
	
}

vector<int> maxRight(vector<int> &height){
	
		
	vector<int> maxRight(height.size());
	int rightmax = 0;
	
	maxRight[height.size() - 1] = rightmax;
	
	for(int i=height.size() - 2; i>=0; i--){
		
		rightmax = max(rightmax, height[i+1]);
		maxRight[i] = rightmax;
	} 
	
	return maxRight;


}

vector<int> maxLeft(vector<int> &height){
	
	vector<int> maxLeft(height.size());
	int leftmax = 0;
	
	maxLeft[0] = leftmax;
	for(int i=1; i<height.size(); i++){
			
		leftmax = max(leftmax, height[i-1]);
		maxLeft[i] = leftmax;
	} 
	
	return maxLeft;
	
}

int trappedWater(vector<int> &height, vector<int> &maxL, vector<int> &maxR, int barWidth){
	
	int waterLevel = 0;
	int trapped = 0;
	for(int i=0; i<height.size(); i++){
		
		waterLevel = min(maxL[i], maxR[i]) - height[i];
		if(waterLevel > 0){
			trapped += waterLevel * barWidth;	
		}
		
	}
	
	return trapped;
}



int main(){
	
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	  
	vector<int> maxL = maxLeft(height);
	vector<int> maxR = maxRight(height);
	
	int water = trappedWater(height,maxL, maxR,1);

	cout << water<<endl;
	return 0;
}
