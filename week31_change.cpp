


#include <iostream>
#include <vector>

using namespace std;


int get_change_naive(int m) {

    int q10= m/10;
    int r10= m%10;

    int q5= r10/5;
    int r5= r10%5;

    return q10+q5+r5;
}

int get_change_greedy(int m) {

    vector<int> denominations{10,5,1};
    int value= m;
    int count= 0;

    for(int i=0; i<denominations.size(); i++){
        while(value>=denominations[i]){
            value -=denominations[i];
            cout<< "value: " << value << endl;
            count++;
        }
    }

    return count;

}


int main() {
    int m;
    std::cin >> m;
    std::cout << get_change_greedy(m) << '\n';
//    std::cout << get_change_greedy(28) << '\n';
//    std::cout << get_change_greedy(91) << '\n';

}
