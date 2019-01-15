#include <iostream>
#include <vector>
using namespace std; 


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
	int rem[60];
	rem[0] = 0;
	int previous = 0;
    int current  = 1;
    int fib = 0;
    int sum = 0;
	for(int i=2;i<=60;i++){
		fib = (previous + current)%10;
        previous = current;
        current = fib;
        rem[i-1] = previous;
        sum = sum + previous;
	}
	
	long long q = n/60;
	int r = n%60;
	int p_sum = 0;
	for(int i=0;i<=r;i++)
	p_sum = p_sum + rem[i];
	
	int total = (q%10)*(sum%10) + (p_sum%10);
	
	return total%10;

}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
