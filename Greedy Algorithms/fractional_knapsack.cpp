#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	vector< pair <double,int> > val; 
	for(int i=0;i<int(values.size());i++)
	val.push_back(make_pair((double)values[i]/weights[i],weights[i]));

	sort(val.begin(),val.end());
	
	int x = values.size()-1;
	
	for(int i=0;i<int(values.size());i++){
		if(capacity == 0)
		return value;
		
		int c_weight = val[x-i].second;
		c_weight = min(capacity,c_weight);
		value += double(c_weight)*val[x-i].first;
		
		capacity = capacity - c_weight; 
		
	}
	
	return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  printf("%.4f", optimal_value);
}
