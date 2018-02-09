//
// Created by vdeshmukh on 2/8/18.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);

    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}

void partition3(vector<int> &a, int l, int r, int &m1, int &m2) {
    int x = a[l];
    int j = l;
    int k = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < x) {
            swap(a[i], a[j]);
            j++;k++;
        }
        else if(a[i]==x){
            swap(a[i], a[k]);
            k++;
        }
    }
    swap(a[l], a[j]);
    m1= j; m2= k;
}

void QuickSort3(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m1, m2;
    partition3(a, l, r, m1, m2);

    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2 + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    QuickSort3(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}

/*
 * Failed case #16/23: Wrong answer (Time used: 1.31/5.50, memory used: 46280704/536870912.)
 * I've implemented the 3-way partioning method, added a check that an array is already sorted.
 * Now testing the case with array that consists of chains of equal elements divided by 1 non-equal.
 * For example 3 3 3 5 7 7 7, or 3 3 3 5 3 3 3. If I stress my code with a chain size like 10^5 it fails with a StackOverFlow error.
 * I've found that it throws this error if m1 == m2 and dives into the infinite cycle of recursive calling to the randomizedQuickSort method.
 * So I think this is the case to be resolved but I'm so stupid to understand how to do it.
 * I thought that if m1 == m2 than other parts are already sorted, but it is not true.
 */

/*
 * 10
 * 5 2 4 2 3 2 1 2 2 2
 * 1 2 2 5 2 2 2 2 3 4
 */