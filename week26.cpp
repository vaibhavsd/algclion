//
// Created by vdeshmukh on 1/20/18.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}



int fibonacci_sum_pro(long long n);

int main() {
    long long n = 0;
    std::cin >> n;
    cout << fibonacci_sum_pro(n) << endl;

}



int fibonacci_sum_pro(long long n){

    int new_n= n%60;
    vector<int> remainder_list;
    remainder_list.push_back(0);
    remainder_list.push_back(1);


    for(int i=2; i<=new_n; i++){
        int j= (remainder_list[i-1] + remainder_list[i-2])%10;
        remainder_list.push_back(j);
    }
    long long sum= 0;


    for(int z=0; z<=new_n; z++)
        sum +=remainder_list[z];


    return sum%10;

}
