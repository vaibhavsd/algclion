

#include <iostream>

using namespace std;


int gcd_pro(int a, int b){
    int l; int s; int remainder;
    if (a>b) {
        l = a;
        s = b;
    }
    else {
        l = b;
        s = a;
    }

//    (a>b?(l=a;s=b):(l=b; s=a))

    if (s==0)
        return l;
    else{
        remainder = l%s;
        return gcd_pro(remainder,s);
    }

}

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

long long lcm_pro(int a, int b){
    return (long long) a*b/gcd_pro(a,b);
}


int main() {
    int a;
    int b;
    std::cin >> a >> b;

    cout<< lcm_pro(a,b) << endl;

//    std::cout << lcm_naive(a, b) << std::endl;

    return 0;
}
