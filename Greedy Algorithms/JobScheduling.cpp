#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define pb push_back

using namespace std;

class Job{
	public: 
	int id;
	int dead;
	int profit;
	
	Job(int id, int dead, int profit){
		this->id = id;
		this->dead = dead;
		this->profit = profit;
	}
};

bool comp(Job a, Job b){
	return a.profit > b.profit;
}

bool compTwo(Job a, Job b){
	return a.dead > b.dead;
}

void scheduleJob(vector<Job> &jobs){
	
	// Intuition : We should schedule the job with highest profit last so that theres space for other jobs
	
	int jobCount = 0;
	int maxProfit = 0;
	
	
	sort(jobs.begin(), jobs.end(), comp);
	
	
	int n = INT_MIN; 
	for(int i = 0; i< jobs.size(); i++){
		int d = jobs[i].dead;
		
		n = max(n,d);
	}
	
	vi sch(n+1, -1);
	
	for(Job job : jobs){
		for(int i=job.dead; i>=1; i--){
			
			if(sch[i] == -1){
				sch[i] = job.id;
				jobCount++;
				maxProfit += job.profit;
				break;
			}
		}
	}
	
	cout << jobCount << " " << maxProfit << endl;
}


int main(){
		int n;
		cin >> n; 
		vector<Job> jobs;
		
		for(int i=0; i<n; i++){
			int id, dead, profit;
			cin >> id >> dead >> profit;
			

			jobs.pb(Job(id,dead,profit));
		}
			
		scheduleJob(jobs);
		
}
