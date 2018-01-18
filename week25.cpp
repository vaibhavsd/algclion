

#include <iostream>
#include <vector>

using namespace std;


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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


bool checkrepeat(vector<long long> list){

    if ((list.size()%2)!=0)
        return false;

    long length= list.size();
    for(long i=0; i<(list.size()/2)-1; i++){
        if (list[i]!=list[(list.size()/2)+i])
            return false;
    }
    return true;
}


long long calculate_pisano_number(long long k){

    vector<long long> remainder_list;
    remainder_list.push_back(0);
    remainder_list.push_back(1);

    int i=2;
    bool condition= false;
    long long a;

    while(!condition){
        a= fibonacci_fast(i);
        remainder_list.push_back(a%k);
        condition= checkrepeat(remainder_list);
        i++;

    }

    return i;
}


//long long get_fibonacci_huge_pro(long long n, long long m){
//
//    long long pisano= calculate_pisano_number(m);
//
//
//    return 0;
//}






int main() {
//    long long n, m;
//    std::cin >> n >> m;
//    std::cout << get_fibonacci_huge_naive(n, m) << '\n';

    for(int i=1; i<10; i++){
        cout<< calculate_pisano_number(i) << endl;
    }


}
