#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool strsort(string a, string b){
	int x = atoi((a+b).c_str());
	int y = atoi((b+a).c_str());
	if(x>y)
	return true;
	else
	return false;
}

string largest_number(vector<string> a) {
  //write your code here
  std::sort(a.begin(),a.end(),strsort);
  
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
