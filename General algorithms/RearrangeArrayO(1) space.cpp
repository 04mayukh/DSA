#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//The values in array should be less than N-1 for the method to work

void arrange(vector<int> &A) {
    
    // vector<int> z;
    
    // for(int i=0;i<A.size();i++)
    // z.push_back(A[i]);
    int N = A.size();
        for(int i = 0; i < N; ++i) {
            A[i] = A[i] + (A[A[i]]%N) * N;
        }

        for(int i = 0; i < N; ++i) {
            A[i] = A[i] / N;
        }
}

int main(){
	vector<int> A;
	A.push_back(4);
	A.push_back(0);
	A.push_back(2);
	A.push_back(3);
	A.push_back(1);
	arrange(A);
	for(int i=0;i<A.size();i++)
	cout<<A[i]<<" ";
	
	
}
