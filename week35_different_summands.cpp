#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  int i= 1;
  long sum= 0;

  while(sum+i<=n){
    summands.push_back(i);
    sum+=i;
    i++;
  }

  long last_element_index= summands.size()-1;
  summands[last_element_index] += n- sum;
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
