#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < (int)swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  
	void shiftUp(vector<int> data_ , vector< pair<int, int> > swaps_ ,int i){
		while(i>1 && (data_[floor((i-1)/2)] > data_[i] ) ){
			int t = data_[i];
			data_[i] = data_[floor((i-1)/2)];
			data_[floor((i-1)/2)] = t;
			swaps_.push_back(make_pair(data_[floor((i-1)/2)],data_[i]));
			i = floor((i-1)/2);
		}
	}
	
	int leftChild(int i){
		return (2*i+1);
	}
	int rightChild(int i){
		return (2*i+2);
	}
	
	void shiftDown(vector<int> &data_ , vector< pair<int, int> > &swaps_ ,int i){
		int maxIndex = i;
		int size = data_.size();
		int l = leftChild(i);
		if(l<size && data_[l] < data_[maxIndex])
		maxIndex = l;
		int r = rightChild(i);
		if(r<size && data_[r] < data_[maxIndex])
		maxIndex = r;
		
		if(i!=maxIndex){
			swap(data_[i],data_[maxIndex]);
			swaps_.push_back(make_pair(i,maxIndex));
			shiftDown(data_,swaps_,maxIndex);
		}
	}

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    int n = data_.size();
    for(int i = floor(n/2)-1; i>=0; i--)
    shiftDown(data_,swaps_,i);
    
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
