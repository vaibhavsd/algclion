
#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_pro(int n){

    if (n <= 1)
        return n;
    std::vector<int> fib_list;
    fib_list.push_back(0);
    fib_list.push_back(1);
    int k;

    for(int i=2; i<=n; i++){
        k = fib_list[i-1] + fib_list[i-2];
        fib_list.push_back(k%10);
    }

    return fib_list[n];

}


int main() {
    int n = 327305;

    int j = get_fibonacci_last_digit_pro(n);
    std::cout << j << std::endl;


//    int c = get_fibonacci_last_digit_naive(n);
//    std::cout << c << '\n';


}