#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

using namespace std;

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

long long MaxPairwiseProductFast(vector<int>& numbers) {

    long long result = 0;
    int n= numbers.size();
    cout<< "n: " << n << endl;
    int max_number_index= 0;
    for(int i=1; i<n; i++){
        if(numbers[i]>numbers[max_number_index])
            max_number_index= i;
    }
    cout<< "max index: " << max_number_index << endl;
    int second_max_number_index;
    if (max_number_index==1)
        second_max_number_index = 0;
    else
        second_max_number_index =1;

    for(int i=0; i<n; i++){
        if((numbers[i]>numbers[second_max_number_index]) && (max_number_index!= i))
            second_max_number_index= i;
    }
    cout<< "second max index: " << second_max_number_index << endl;
//    result= numbers[max_number_index] * numbers[second_max_number_index];

    return (long long) numbers[max_number_index] * numbers[second_max_number_index];
}

int main() {
    int n=2;
//    cin >> n;
    vector<int> numbers(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
    numbers[0]= 90000;
    numbers[1]= 100000;

    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}
