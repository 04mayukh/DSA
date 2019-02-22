#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < (int)jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }


	int leftChild(int i){
		return (2*i+1);
	}
	int rightChild(int i){
		return (2*i+2);
	}
	
	void shiftDown(vector< pair<long long,int> > &data_ , int i){
		int maxIndex = i;
		//int maxIndex_id = i;
		int size = data_.size();
		int l = leftChild(i);
		if(l<size && data_[l].first <= data_[maxIndex].first){
			if(data_[l].first < data_[maxIndex].first)
			maxIndex = l;
			if(data_[l].first == data_[maxIndex].first && data_[l].second < data_[maxIndex].second)
			maxIndex = l;
		}
		int r = rightChild(i);
		if(r<size && data_[r].first <= data_[maxIndex].first){
			if(data_[r].first < data_[maxIndex].first)
			maxIndex = r;
			if(data_[r].first == data_[maxIndex].first && data_[r].second < data_[l].second)
			maxIndex = r;
		}
		
		if(i!=maxIndex){
			swap(data_[i].first,data_[maxIndex].first);
			swap(data_[i].second,data_[maxIndex].second);
			shiftDown(data_,maxIndex);
		}
	}

	void AssignJobs() {
		vector< pair<long long,int> > H(num_workers_);
		for(int i=0; i<num_workers_; i++){
			H[i].first = 0;
			H[i].second = i;
		}
		//for(int i = floor(H.size()/2)-1; i>=0; i--)
		//shiftDown(H,i);
		
		int m = jobs_.size();
		for(int i=0; i<m; i++){
			int id = H[0].second;
			long long t = H[0].first;
			assigned_workers_.push_back(id);
			start_times_.push_back(t);
			H[0].first = H[0].first + jobs_[i];
			shiftDown(H,0); 
		}
	}

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
