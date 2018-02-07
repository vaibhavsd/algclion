#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool myfunction (Segment i,Segment j) { return (i.start <j.start); }


vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;


  sort(segments.begin(), segments.end(), myfunction);

  int last_element;
  long current_size;
  int count_to_be_deleted= 0;

  while(!segments.empty()){
    last_element= segments[0].end;
    current_size = segments.size();
    for(int i=1; i< current_size; i++){
      if(segments[i].start<= last_element) {
        count_to_be_deleted++;
        if(segments[i].end<last_element)
          last_element= segments[i].end;
      }
      else
        break;
    }

    segments.erase(segments.begin(), segments.begin()+ count_to_be_deleted+ 1);
    count_to_be_deleted = 0;
    points.push_back(last_element);
  }

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
