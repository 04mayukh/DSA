#include <iostream>

// Find the last digit of each fibonaci number and keep adding it. 

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n){
	int prev = 0;
	int current = 1;
	int fib = 0;
	if(n==0)
	return 0;
	int sum = 1;
	for(int i=2;i<=n;i++){
		fib = (prev+current)%10;  //Last digit of number.
		prev = current;
		current = fib;
		sum = sum + fib;   //Sum the last digits.
	}
	return sum%10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
