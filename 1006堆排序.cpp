#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;

vector <int> arr;
void Change(int p, int n) {
    int t = 2 * p + 1;
    if (t+1 >= n) {
        if (arr[p] > arr[t])swap(arr[p], arr[t]);
    }
    else {
        if (arr[p] <= arr[t] && arr[p] <= arr[t+1])return;
        else {
            if (arr[t] <= arr[t+1])swap(arr[p], arr[t]);
            else swap(arr[p], arr[t+1]);
        }
    }
    return;
}

void HeapSort(int n) {
    int p = (n - 2) / 2 + 1;
    while (p--) {
        Change(p, n);
        int t = p;
        while (2 * t + 1 < n) {
            Change(t, n);
            t++;
        }
    }
}

int main() {
    int m, n, t;
    cin >> m;
    while (m--) {
        cin >> n;
        arr.clear();
        for (int i = 0; i < n; ++i) {
            cin >> t;
            arr.push_back(t);
        }
        HeapSort(n);
        for (auto item : arr) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}

