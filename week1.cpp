#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = 0;
    int n= numbers.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(numbers[i]*numbers[j]>result)
                result = numbers[i]*numbers[j];
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    long long result = 0;
    int n= numbers.size();

    int max_number_index= 0;
    for(int i=0; i<n; i++){
        if(numbers[i]>numbers[max_number_index])
            max_number_index= i;
    }
    int second_max_number_index= 0;
    for(int i=0; i<n; i++){
        if((numbers[i]>numbers[second_max_number_index]) && (max_number_index!= i))
            second_max_number_index= i;
    }
    result= numbers[max_number_index] * numbers[second_max_number_index];

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}
