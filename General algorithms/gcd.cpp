#include <iostream>

// The Naive method is very slow and takes O(n^2) time which is very slow.
// The fast method using euclids algo is very fast and takes around O(logn) time.

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a,int b){
	if(a==0)
	return b;
	else
	return gcd_fast(b%a,a);
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
