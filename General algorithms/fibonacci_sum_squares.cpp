#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }
    return sum % 10;
}


int fibonacci_sum_squares_fast(long long n) {
	int rem[60];
	rem[0] = 0;
	int previous = 0;
    int current  = 1;
    int fib = 0;
	for(int i=2;i<=60;i++){
		fib = (previous + current)%10;
        previous = current;
        current = fib;
        rem[i-1] = previous;
	}
	int r = n%60;
	int a = rem[r];
	int b;
	if(r!=0)
	b = rem[r-1];
	else
	b = rem[59];
	
	int result = a*(a+b);
	return result%10;
	
}





int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
