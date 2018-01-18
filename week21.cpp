#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {

    std::vector<long long> list;
    list.push_back(0);
    list.push_back(1);

    if (n<=1){
        return list[n];
    }

    for(int i=2; i<=n; i++){
        list.push_back(list[i-1] + list[i-2]);
    }
    return list[n];

}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n;
    std::cin >> n;

//    std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
