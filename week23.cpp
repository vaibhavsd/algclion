
#include <iostream>

using namespace std;



int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}


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



int main() {
    int a;
    int b;
    cin >> a >> b;

    cout << gcd_pro(a,b) << endl;
//    std::cout << gcd_naive(a, b) << std::endl;


    return 0;
}
