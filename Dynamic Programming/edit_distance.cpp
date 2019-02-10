#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.length();
  int n = str2.length();
  int edit[m+1][n+1];
  for(int i=0; i<=m; i++)
  edit[i][0] = i;
  for(int i=0; i<=n; i++)
  edit[0][i] = i;
  
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			int ins = edit[i][j-1] + 1;
			int del = edit[i-1][j] + 1;
			int mis = edit[i-1][j-1] + 1;
			int mat =  edit[i-1][j-1];
			if(str1[i-1] == str2[j-1])
			edit[i][j] = min(min(ins,del),mat);
			else
			edit[i][j] = min(min(ins,del),mis);
		}
	}
  
  return edit[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
