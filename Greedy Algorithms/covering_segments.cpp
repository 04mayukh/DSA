#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool segsort(struct Segment&a,struct Segment&b){
	return (a.start<b.start);
}

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
  //write your code here
	sort(segments.begin(),segments.end(),segsort);
	for (size_t i = 0; i < segments.size()-1 ; ++i) {
		//std::cout<<segments[i].start<<' '<<segments[i].end<<std::endl;
		if(segments[i].end >= segments[i+1].start){
			 segments[i+1].end = std::min(segments[i].end,segments[i+1].end);
		}
		else
		points.push_back(segments[i].end);
	}
	points.push_back(segments[segments.size()-1].end);
	
	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
