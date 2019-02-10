#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long fibonacci(int n, vector<long> &fib){
	if(fib[n] != -1)
	return fib[n];
	fib[n] = fibonacci(n-2,fib) + fibonacci(n-1,fib) ;
	return fib[n];
}



int main() {
  int m;
  std::cin >> m;
  vector <long> fib(m+1,-1);
  fib[0] = 0;
  fib[1] = 1;
  std::cout << fibonacci(m,fib) << '\n';
  for(int i=0;i<=m;i++)
  cout<<fib[i]<<" ";
}
