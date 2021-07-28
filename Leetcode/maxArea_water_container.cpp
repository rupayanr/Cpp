#include <bits/stdc++.h>
using namespace std;

/* Problem Statement: (Max water container area)
	Given a vector of heights calculate the maximum area made by using the values and width if the vector indices

	ALGO 
	1) Start two pointers from Front and Back 
	2) Calculate width using diff of back and front 
	3) Calculate min length using min(height[front], height[back])
	4) Calc Area and add to final vector 
		4.a) if front + 1 < N  && nums[front+1] > nums[front] front++
		4.b) if back - 1 > front && nums[back - 1] > nums[back] back--
	5) Calc maximum of final vector thats the max area possible 
		
	*/

int maxArea(vector<int> &height){
	
	int front = 0;
	int back = height.size() - 1;
	int a = 0;
	while(front < back){
		
		int h = min(height[front], height[back]); // 1,7 -> 1 8,7 -> 7 // 8,8 -> 8
		a = max(a,(back-front)*h); // 8 // 49 // 40 
			
		while(height[front] <= h && front<back) front++; // T front = 2 8<=7 
		while(height[back] <= h && front <back ) back--;  // 8 

	}
	
	return a;
}

int main(){
	
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	int ans = maxArea(height);
	cout << ans << endl;
	
}
