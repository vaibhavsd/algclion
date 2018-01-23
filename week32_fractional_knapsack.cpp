#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    vector<int> valueperweight;
    std::transform( values.begin(), values.end(), weights.begin(), back_inserter(valueperweight), std::divides<double>() );



//    while(){
//
//
//    }

  return value;
}

int main() {
  int n= 3;
  int capacity= 50;
//  std::cin >> n >> capacity;
  vector<int> values={60,100,120};
  vector<int> weights= {20,50,30};
//  for (int i = 0; i < n; i++) {
//    std::cin >> values[i] >> weights[i];
//  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
