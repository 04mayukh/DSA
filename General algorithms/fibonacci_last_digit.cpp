#include <iostream>

//Instead of storing the whole numbers just store the last digit in each iteration.This prevents memory overflow and speeds up the program

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int fib = 0;

    for (int i = 2; i <= n ; ++i) {
        fib = (previous + current)%10;
        previous = current;
        current = fib;
    }

    return fib;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
