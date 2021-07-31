#include <bits/stdc++.h>
#define vi vector<int> 

using namespace std;

/*
	Alogrithm 
	Naiive 
	1) Using merge sort construct a merged array
	2) Then calculate median of merged sorted array 
		2.a) if median len is even then median = temp[size - 1/2] + temp[size/2] // 2
		2.b) if median len is odd then median = temp[size - 1/2]
	3) return median 

 */ 

void display(vi &nums){
	
	for(int val : nums){
		cout << val << " ";
		
	}
	cout << endl;
}



double findMedianOpti(vi &a, vi &b){
	
	
	/* 
		Optimal intuition 
		We will try to segragate the two arrays based on a condition 
		
		it might happen that aleft or bleft becomes equal to hi 
		then they become inaccessible as they are out of bound of the array 
		
		int lo=0, hi=a.len, te=a.len + b.len
		while( lo <= hi)
			aleft = (lo + hi)/2
			bleft = te+1/2 - aleft 
		
		alm1 = (aleft == 0) ? INT_MIN : a[aleft - 1]
		al = (aleft == a.length) ? INT_MAX : a[aleft]
		
		blm1 = (bleft == 0) ? INT_MIN : b[bleft - 1]
		bl = (bleft == b.length) ? INT_MAX : b[bleft]
		
		a[aleft - 1] <= b[bleft] && a[aleft] >= b[bleft - 1] // valid 
			
			if(te % 2 == 0)
			lmax = max(alm1, blm1)
			rmax = max(al, bl)
			return lmax + rmax / 2.00000
		
		a[left - 1] > b[bleft] hi = aleft - 1;
		
		b[bleft - 1] > a[aleft] lo = aleft + 1;
		
		
		there could be a case where bleft turns negative with high val of a 
		
		so we can solve this by swapping a and b vectors 
			
	
	*/
	
	if(a.size() > b.size()){
		return findMedianOpti(b,a);
	}
	
	
	int lo = 0, hi = a.size(), te = a.size() + b.size();

	while(lo <= hi){
		
		// Calculates aleft and bleft indexes i.e the no of elements from a and b to be put in lower half 
		int aleft = (hi + lo)/2;
		int bleft = (te+1)/2 - aleft;
	
		// Edge conditions 
		
		int blm1 = (bleft == 0) ? INT_MIN : b[bleft - 1];
		int alm1 = (aleft == 0) ? INT_MIN : a[aleft - 1];
		
		int bl = (bleft == b.size()) ? INT_MAX : b[bleft]; 
		int al = (aleft == a.size()) ? INT_MAX : a[aleft];
		
		
		
		
		// Valid segragation 
		if(alm1 <= bl && al >= blm1){
			double median = 0.00000;

			
			if(te % 2 == 0){
				int lmax = max(alm1, blm1);
				int rmax = min(al,bl);
				median = (lmax + rmax)/2.00000;
				return median;
			}
			else{
				int lmax = max(alm1, blm1);
				median = lmax;
				return median;
			}
			
		}
		
		
		// Invalid Cases
		// If alm1 > bl
		else if(alm1 > bl){
			// that means we have to pick more elements of b and shift mid of a to left
			hi = aleft - 1;
		}
		
		else if(al < blm1){
			// we have to select more of a elements adn move mid to right of a
			lo = aleft + 1;
		}
		
	} 
	
	
}


void mergedArray(vi &a, vi &b, vi &aux){
	
	
	int i=0, j=0, k=0;
	
	while(i < a.size() && j < b.size() && k < aux.size()){
		
		if(a[i] < b[j]){
			aux[k++] = a[i++];
		}
		else if(a[i] > b[j]){
			aux[k++] = b[j++];
		}
		else{
			aux[k++] = a[i++];
			aux[k++] = b[j++];	
		}	
	}
	
	while(i < a.size()){
		aux[k++] = a[i++];
	}
	
	while(j < b.size()){
		aux[k++] = b[j++];
	}

	
}


double findMedianSortedArrays(vi &a, vi &b){
	
	
	double median = 0;
	vi temp(a.size() + b.size());
	
	mergedArray(a,b, temp);
	display(temp);
	
	// { 1 2 3 4 5 6 7 8 9 10 }
	int n = temp.size(); // 10
	if(n == 1){
		return temp[0];
	}
	
	if(n % 2 == 0){
		// Array size is even 
		median = (temp[(n-1)/2] + temp[n/2]) / 2.0000;
			
	}
	else{
		// Array size is odd
		median = temp[(n-1)/2];
	}
	
	return median;
}


int main(){
	
	//vi a = { 1, 3, 5, 6, 7 };
	//vi b = { 2, 4, 8, 9, 10 };
	
	vi a = {1,3};
	vi b = {2};
	
	//double median = findMedianSortedArrays(a,b);
	double median = findMedianOpti(a,b);
	cout.precision(5);
	cout << fixed << median  << endl;
}
