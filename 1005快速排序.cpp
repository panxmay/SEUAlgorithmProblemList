#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;

vector <int> arr;

int Partition(int low, int high) {
    int x = arr[low];
    int p = low, i = low + 1;
    while (i < high) {
        if (arr[i] < x) { 
            swap(arr[++p], arr[i]);
        }
        i++;
    }
    swap(arr[low], arr[p]);
    return p;
}

void QuickSort(int low, int high) {
    if (low < high) {
        int p = Partition(low, high);
        Partition(low, p);
        Partition(++p, high);
    }
    return;
}

int main() {
    int m, n, temp;
    cin >> m;
    while (m--) {
        cin >> n;
        arr.clear();
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            arr.push_back(temp);
        }
        QuickSort(0,n);
        for (auto item : arr) {
            cout << item<<" ";
        }
        cout << endl;
    }
    return 0;
}


