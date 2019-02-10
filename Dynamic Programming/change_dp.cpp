#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int get_change(int m) {
	int coins[3] = {1,3,4};
	vector<int> change(m+1,INT_MAX);
	change[0] = 0;
	
	for(int i=1; i<=m; i++){
		int minNum = INT_MAX;
		
		for(int j=0; j<3; j++){
			if(i>=coins[j]){
				minNum = change[i - coins[j]] + 1;
				if(minNum < change[i])
				change[i] = minNum;
			}
		}
	}
  //write your code here
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
