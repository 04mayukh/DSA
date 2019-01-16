#include <iostream>
#include <cmath>

using namespace std;
int isPower(int A) {
    double y = 0.0;
    if(A==1)
    return true;
    int x = sqrt(A);
    for(int i=2;i<=x;i++){
        y = log10(A)/log10(i);
        if(y<1)
        return false;
        if(ceil(y)==floor(y) && y>1)
        return true;
    }
    return false;
}

int main(){
	int x;
	cin>>x;
	cout<<isPower(x);
}
