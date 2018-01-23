//
// Created by vdeshmukh on 1/23/18.
//

#include <iostream>
#include <vector>

using namespace std;

int minNoOfStops(vector<int> list, int stations, int L){

    int nextstop;
    int laststop= list[stations+1];
    int totalstops= 0;
    int iamhere= list[0];
    int i=1;

    while(iamhere!=laststop){

    while (list[i] - iamhere <= L  &&  list[i]!=laststop) {
//        cout << "ns " << list[i] << endl;
        i++;
    }
    totalstops++;
    iamhere = list[i-1];
    cout << "next stop: " << list[i-1] << endl;

    if(list[i]==laststop){
        break;
    }

    if(list[i]- iamhere>L){
        cout<< "Impossible" << endl;
        break;
    }

    }

    return totalstops;
}


int main(){

    vector<int> list{200,300,400,500,700,870,950};
    int stations= list.size()-2;
    int L= 200;

    cout << minNoOfStops(list,stations, L) << endl;



    return 0;
}