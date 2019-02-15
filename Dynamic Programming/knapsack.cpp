#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

int optimal_weight(int W, const vector<int> &wt) {
  //write your code here
	vector<vector<int> > r(wt.size()+1,vector<int> (W+1,0));
	for(int i=0; i<=(int)wt.size();i++)
	r[i][0] = 0;
	for(int i=0; i<=W;i++)
	r[0][i] = 0;
	
	for(int i=1; i<=(int)wt.size(); i++){
		for(int w=1; w<=W; w++){
			r[i][w] = r[i-1][w];
			int val = 0;
			if(w>=wt[i-1])
			{
				val = r[i-1][w-wt[i-1]] + wt[i-1];
				r[i][w] = std::max(val,r[i][w]);
			}
		}
	}
	
	for(int i=1; i<=(int)wt.size();i++){
		cout<<wt[i-1]<<"HAHA";
		for(int j=0; j<=W; j++)
		std::cout<<r[i][j]<<" ";
		std::cout<<endl;
	}
	
	return r[wt.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> wt(n);
  for (int i = 0; i < n; i++) {
    std::cin >> wt[i];
  }
  sort(wt.begin(), wt.end()); 
  std::cout << optimal_weight(W, wt) << '\n';
}
