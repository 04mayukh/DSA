#include <iostream>
#include <vector>
using namespace std;

// This program uses the concept of Pisano period. It is calculated by running an infinite loop untill repeating 0 1 sequence is found.
// At the same time remainders are stored.Remember we need not calculate the Fn number but just store their remainders.  

long long get_fibonacci_huge_fast(long long n, long long m) {
    int previous = 0;
    int current  = 1;
    int fib = 0;
    int period =2;
    vector<int> remainders;
    remainders.push_back(0);
    while(true) {
        fib = (previous + current)%m;
        previous = current;
        current = fib;
        if((previous)==0 && (current)==1){
			period--;
			break;
		}
        else{
			remainders.push_back(previous%m);
			period++;
		}
    }
    return remainders[n%period];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
