#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

vector<int> optimal_sequence_greedy(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


vector<int> optimal_sequence(int n) {
	vector<int> sequence;
	vector<int> count(n+1,9999);
	count[0] = 0;
	count[1] = 0;
	if(n==1){
		sequence.push_back(1);
		return sequence;
	}
	
	for(int i=2; i<=n; i++){
		int a,b,c;
		a=b=c=INT_MAX;
		if(i%2 == 0){
			a = count[i/2] + 1;
		}
		if(i%3 == 0){
			b = count[i/3] + 1;
		}
		c = count[i-1] + 1;

		
		count[i] = min(min(a,b),c);
		//cout<<i<<" "<<count[i]<<endl;
		//cout<<a<<" "<<b<<" "<<c<<endl;
	}
	for(int i=count[n];i>=0;i--){
		pair<int,int> a,b,c,d;
		a.first = b.first = c.first = INT_MAX;
		sequence.push_back(n);
		if(n%2 == 0){
			a.first = count[n/2];
			a.second = n/2;
		}
		if(n%3 == 0){
			b.first = count[n/3];
			b.second = n/3;
			
		}
		c.first = count[n-1];
		c.second = n-1;
		
		d = min(min(a,b),c);
		n = d.second;	
		
		if(a.first == b.first && a.first < c.first){
			n = a.second;
		}
		
	}
	reverse(sequence.begin(),sequence.end());
	return sequence;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size()-1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

