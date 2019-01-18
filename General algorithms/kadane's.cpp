#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &A) {
    int max_so = 0;
    int max = -99999;
    for(int i=0;i<A.size();i++){
        max_so += A[i];
        if(max<max_so)
        max = max_so;
        if(max_so<0)
        max_so=0;
    }
    
    return max;
}

int main(){
	vector<int> arr;
	arr.push_back(-2);
	arr.push_back(-3);
	arr.push_back(4);
	arr.push_back(-1);
	arr.push_back(-2);
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(-3);
	cout<<maxSubArray(arr);
}    
