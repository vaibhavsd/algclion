#include <iostream>
#include <vector>

using namespace std;


long long get_fibonacci_huge_pro(long long n, long long m);

int main(){

//    cout<< get_fibonacci_huge_pro(99999999999999999, 2) << endl;
//    cout<< get_fibonacci_huge_pro(2816213588, 40000) << endl;
//    cout<< get_fibonacci_huge_pro(9999999999, 100000) << endl;
//    cout<< get_fibonacci_huge_pro(100, 100000) << endl;
//
//    cout<< get_fibonacci_huge_pro(239, 1000) << endl;
//    cout<< get_fibonacci_huge_pro(2816213588, 30524) << endl;

    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_pro(n, m) << '\n';



}


long long get_fibonacci_huge_pro(long long n, long long m){

    vector<long long> remainder_list;
    remainder_list.push_back(0);
    remainder_list.push_back(1);

    long long i=2;
    while(true){
        long long j= (remainder_list[i-1] + remainder_list[i-2])%m;
        remainder_list.push_back(j);
        i++;
        if(remainder_list[i-1]==1 && remainder_list[i-2]==0)
            break;

    }

    long long pisano= i-2;
    long long index= n%pisano;

    return remainder_list[index];

}



