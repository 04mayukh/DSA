#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
using std::vector;


int binary_search(vector< pair<int,int> > a,int n){
	int l = 0;
	int r = a.size()-1;
	int pos = 0;
	while(l<=r){
		int mid = (l+r)/2;
		if(a[mid].first == n){
			pos =  mid;
			break;
		}
		else if(a[mid].first > n)
		r = mid-1;
		else
		l = mid+1;
	}
	while(a[pos].first==a[pos-1].first)
	pos--;
	
	return pos;
		
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	int p = points.size();
	int s = starts.size();
	vector< pair< int, char > >pts;
	
	vector< pair< int, int > >in;
	for(int i=0;i<p;i++){
		pts.push_back(make_pair(points[i],'p'));
		in.push_back(make_pair(points[i],i));
	}
	for(int i=0;i<s;i++)
	pts.push_back(make_pair(starts[i],'l'));
	
	for(int i=0;i<s;i++)
	pts.push_back(make_pair(ends[i],'r'));
	
	int segment = 0;
	
	sort(pts.begin(),pts.end());
	sort(in.begin(),in.end());
	
	//for(int i=0;i<pts.size();i++)
	//cout<<"("<<pts[i].first<<","<<pts[i].second<<")"<<"  ";
	//cout<<endl;
	
	for(int i=0;i<(int)pts.size();i++){
		if(pts[i].second == 'p'){
			int x = pts[i].first;
			int y = binary_search(in,x);
			cnt[in[y].second] = segment;
			y++;
			while(pts[i].first==pts[i+1].first && pts[i].second==pts[i+1].second){
				cnt[in[y].second] = segment;
				y++;
				i++;
			}
		}
		if(pts[i].second == 'l' )
		segment++;
		if(pts[i].second == 'r' )
		segment--;
	}
	
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
