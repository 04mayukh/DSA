#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
	if (right == left ) return number_of_inversions;
	long long ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
	long long i = left;
	long long k = left;
	long long j = ave+1;
	while(k<=ave && j<=right){
		if(a[k] <= a[j]){
			b[i] = a[k];
			i++;
			k++;
		}
		else{
			number_of_inversions += ave-k+1;
			b[i] = a[j];
			j++;
			i++;
		}
	}
	for(long long m=k; m<=ave; m++){
		b[i] = a[m]; 
		i++;
	}
	
	for(long long m=j; m<=right; m++){
		b[i] = a[m];
		i++;
	}
	for(long long i=left; i<=right; i++){
		a[i] = b[i];
	}

	//write your code here
	return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';

}
