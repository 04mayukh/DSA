#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a,int b){
    if(a==0)
    return b;
    else
    return gcd(b%a,a);
}


int cpFact(int A, int B) {
        while(true){
            if(gcd(A,B)==1)
            return A;
            A = (A/gcd(A,B));
        }
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<cpFact(a,b);
	return 0;
}
