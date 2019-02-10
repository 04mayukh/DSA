#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



int get_change_rec(int m, vector<int> &change) {
	int coins[3] = {1,3,4};
	if(change[m] != INT_MAX)
	return change[m];
	
	int minNum = INT_MAX;
	for(int i=0; i<3; i++){
		if(m >= coins[i]){
			minNum = get_change_rec(m - coins[i],change) + 1;
			if(minNum < change[m])
			change[m] = minNum;
		}
	}
	
	return change[m];
}



int main() {
  int m;
  std::cin >> m;
  vector<int> change(m+1,INT_MAX);
  change[0] = 0;
  std::cout << get_change_rec(m,change) << '\n';
}
