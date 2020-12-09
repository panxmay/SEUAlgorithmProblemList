#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;

vector <int> arr,temp;
int flag;

void Merge(int l1,int h1,int l2,int h2) {
    if (h2 - l1 >= flag)return;
    int i = l1, j = l2;
    temp.clear();
    while (i <= h1 && j <= h2) {
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= h1) {
        temp.push_back(arr[i++]);
    }
    while (j <= h2) {
        temp.push_back(arr[j++]);
    }
    i = 0;
    j = l1;
    while (j <= h2) 
        arr[j++] = temp[i++];
}


void MergeSort(int low, int high) {
    if (low >= high)return;
    int m = (low + high) / 2;
    MergeSort(low, m);
    MergeSort(m + 1, high);
    if(flag)Merge(low, m, m+1, high);
}

int main() {
    int m, n, t;
    cin >> m;
    while (m--) {
        cin >> n;
        // flag保证只会递归到倒数第三层
        int a = log2(n-1) - 1 ;
        flag = pow(2,a);
        arr.clear();
        for (int i = 0; i < n; ++i) {
            cin >> t;
            arr.push_back(t);
        }
        MergeSort(0,n-1);
        for (auto item : arr) {
            cout << item<<" ";
        }
        cout << endl;
    }
    return 0;
}


