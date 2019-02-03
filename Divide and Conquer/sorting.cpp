#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

vector<int> partition3(vector<int> &a, int l, int r){
    int x = a[l];
    int p_l = l;
    int i = l+1;
    int p_e = r;
    vector<int> m(2);
    while (i <= p_e) {
        if (a[i] < x) {
            swap(a[p_l], a[i]);
            p_l++;
            i++;
        } else if (a[i] == x) {
            i++;
        } else {
            swap(a[i], a[p_e]);
            p_e -= 1;
        }
        m[0] = p_l;
        m[1] = p_e;
    }
	cout<<x<<endl;
	cout<<(p_l)<<"  "<<(p_e)<<endl;
	for (size_t i = 0; i < a.size(); ++i) 
    std::cout << a[i] << ' ';
    cout<<endl<<endl;
	return m;
}


int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
	  //cout<<endl<<l<<" "<<r<<endl;
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> u = partition3(a, l, r);
  int m = u[0];
  int n = u[1];
  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, n + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
