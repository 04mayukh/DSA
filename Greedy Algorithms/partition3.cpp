#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using std::vector;
using namespace std;


int optimal_weight(int W, vector<int> &wt) {
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
	
	for(int i=0; i<=(int)wt.size(); i++){
		for(int j=0; j<=W; j++)
		cout<<r[i][j]<<" ";
		cout<<endl;
	}
	
	
	for(int j=1;j<=(int)wt.size(); j++){
	if(r[j][W] == W){
		int weight = W;
		for(int i=j; i>0 && weight!=0; i--){
			if(r[i-1][weight-wt[i-1]] + wt[i-1] == r[i][weight]){
				weight -= wt[i-1];
				wt[i-1] = 0;
			}
		}
		return W;
	}
	}
	return 0;
	
}




int partition3(vector<int> &A) {
  int sum = 0;
  for(int i=0; i<(int)A.size();i++)
  sum += A[i];
  
  float p = sum/3.0;
 
  if(floor(p) != ceil(p))
  return 0;
  
  if(A.size()<3)
  return 0;
  
  int x = optimal_weight(p,A);
  if(x!=p)
  return 0;
  
  for(int i=0; i<(int)A.size(); i++)
  std::cout<<A[i]<<" ";
  std::cout<<endl;
  
  x = optimal_weight(p,A);
  if(x!=p)
  return 0;
  for(int i=0; i<(int)A.size(); i++)
  std::cout<<A[i]<<" ";
  std::cout<<endl;
  
  return 1;
	
/*  for(int i=0; i<(int)A.size(); i++)
  std::cout<<A[i]<<" ";
  std::cout<<endl;
  
  x = optimal_weight(p,A);
  if(x!=p)
  return 0;
  for(int i=0; i<(int)A.size(); i++)
  std::cout<<A[i]<<" ";
  std::cout<<endl;
  
  x = optimal_weight(p,A);
  if(x!=p)
  return 0;
  for(int i=0; i<(int)A.size(); i++)
  std::cout<<A[i]<<" ";
  std::cout<<endl;
  
  for(int i=0; i<(int)A.size(); i++)
  if(A[i]!=0)
  return 0;
  
  return 1;
*/  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  sort(A.begin(),A.end(),greater<int>());
  std::cout << partition3(A) << '\n';
}
