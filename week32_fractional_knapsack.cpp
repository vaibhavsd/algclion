#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    vector<double> valueperweight;
//    std::transform( values.begin(), values.end(), weights.begin(), back_inserter(valueperweight), std::divides<float>() );

    for(int i=0; i< weights.size(); i++)
        valueperweight.push_back((double)values[i]/(double)weights[i]);

    std::vector<double>::iterator max_el;


    long max_el_index;
    double available_capacity= capacity;

    while(available_capacity>0) {

        max_el = std::max_element(valueperweight.begin(), valueperweight.end());
        if(*max_el!= -1) {
            max_el_index = std::distance(valueperweight.begin(), max_el);

            if (weights[max_el_index] < available_capacity) {
                value += values[max_el_index];
                available_capacity -= weights[max_el_index];
            } else {
                value += (double) valueperweight[max_el_index] * available_capacity;
                available_capacity = 0;
            }
            valueperweight[max_el_index] = -1;
        }
        else
            break;
    }

//    while(){
//
//
//    }

  return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}