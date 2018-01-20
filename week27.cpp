//
// Created by vdeshmukh on 1/20/18.
//

#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long get_fibonacci_partial_sum_pro(long long from, long long to) {


    // Think: Sum 7 to 14 is same as sum 7 to 74.
    // Sum from 6 to 8 is same as sum 6 to 68.
    //Proof:
    // 6->128= 6->60 + 60->120 + 120->6 + 6->8
    // 6->128= 6->60 + 0 + 120->6 + 6->8
    // 6->128= 6->60 + 120->6 + 6->8
    // 6->128= 10*constant + 6->8
    // 6->128 %10 = 10*constant %10 + 6->8 %10
    // 6->128 %10 = 0 + 6->8 %10


    vector<int> remainder_list;
    remainder_list.push_back(0);
    remainder_list.push_back(1);
    for(int i=2; i<=60; i++){
        int j= (remainder_list[i-1] + remainder_list[i-2])%10;
        remainder_list.push_back(j);
    }

    int first = from % 60;
    int second = to % 60;
    int sum= 0;


    if (from > to) {

        for(int z=first; z<=60; z++)
            sum +=remainder_list[z];

        for(int z=0; z<=second; z++)
            sum +=remainder_list[z];


    }

    else {
        for(int z=first; z<=second; z++)
            sum +=remainder_list[z];
    }

    return sum%10;

}



int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_pro(from, to) << '\n';
//    std::cout << get_fibonacci_partial_sum_pro(10, 10) << '\n';
//    std::cout << get_fibonacci_partial_sum_pro(10, 200) << '\n';

}
