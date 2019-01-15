#include <iostream>
#include <cassert>

// This contains 2 algorithms for computing fibonacci number.
// One uses recursion which takes exponential time.
// The second one takes O(n.) times using a simple for loop

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int N) {
    int64_t n = 1;
    int64_t n_minus_1 = 0;
    int64_t fib = 0;
    
    if(N==1)
    return 1;
    
    for(int i=2;i<=N;i++){
		fib = n + n_minus_1;
		n_minus_1 = n;
		n = fib;
	}
    return fib;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    ///std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
