#include <iostream>

// The naive algo uses 2 for loops making the time complexity O(n^2).
// The fast algo uses the gcd to compute the lcm reducing the time complexity to O(log(n)).

long long lcm_naive(long long a, long long b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(long long a,long long b){
	if(a==0)
	return b;
	else
	return gcd_fast(b%a,a);
}

long long lcm_fast(long long a,long long b){
	int gcd = gcd_fast(a,b);
	return((a*b)/gcd);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
