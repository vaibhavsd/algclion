#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


string largest_number(vector<string> a) {
    //write your code here
    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];

    }
    string result;
    ret >> result;
    return result;
}


long LargestNumber(vector<long> a) {
    //write your code here
    std::stringstream answer;
    string result;
    int max;

    while(a != empty) {
        max= -INFINITY;
        for (size_t i = 0; i < a.size(); i++) {
            if(a[i]>max)
                max= a[i];
        }
        answer << max;
        answer >> result;

    }

    return result;
}




int main() {
    int n=1;
//    std::cin >> n;
    vector<long> a= {235};
//    for (size_t i = 0; i < a.size(); i++) {
//        std::cin >> a[i];
//    }

    std::cout << largest_number(a);
}
