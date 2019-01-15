#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long get_fibonacci_partial_sum_fast(long long start, long long end){
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
	
	long long x = start/60;
	long long y = end/60;
	int p_sum = 0;
	if(x==y){
		for(int i=start%60;i<=end%60;i++)
		p_sum = p_sum + rem[i];
		return p_sum%10;
	}
	else{
		for(int i=start%60;i<60;i++)
		p_sum = p_sum + rem[i];
		for(int i=0;i<=end%60;i++)
		p_sum = p_sum + rem[i];
		
		int total;
		if((y-x)>1)
		total = ((y-x)%10)*(sum%10) + (p_sum%10);
		else
		total = (p_sum%10);
		
		return total%10;
	}

}





int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
