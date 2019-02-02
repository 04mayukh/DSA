#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
  if (left + 1 == right) return a[left];
  //write your code here
	int mid = floor((left+right)/2);
	
	int l = get_majority_element(a, left, mid);
	int r = get_majority_element(a, mid+1, right);
	if(l != -1){
		int count = 0;
		for(int i=left;i<=right;i++){
			if(a[i] == l)
			count++;
		}
		if(count > ((right-left+1)/2))
		return l;
	}
	if(r != -1){
		int count = 0;
		for(int i=left;i<=right;i++){
			if(a[i] == r)
			count++;
		}
		if(count > ((right-left+1)/2))
		return r;
	}
	return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
