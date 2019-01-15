#include <iostream>
#include <vector>
#include <algorithm>


int64_t MaxPairwiseProduct(const std::vector<long long>& numbers) {
    int64_t max_product = 0;
    int n = numbers.size();
	int index1,index2=0;
	for(int i=1;i<n;i++)
	{
		if(numbers[i]>numbers[index1])
		index1 = i;
	}
	
	if(index1==0)
	index2=1;
		
	for(int i=1;i<n;i++)
	{
		if(numbers[i]>numbers[index2] && i!=index1)
		index2 = i;
	}
	max_product = numbers[index1]*numbers[index2];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int64_t result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
