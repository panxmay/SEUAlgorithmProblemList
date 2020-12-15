#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#define INF 0X7FFFFFFF
using namespace std;

vector<int> arr1,arr2;
unordered_map<int, int> hs;
int sum;

void Merge(int l1, int r1, int l2, int r2) {
    arr2.clear();
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) {
        if (arr1[j] < arr1[i]) {
            arr2.push_back(arr1[j++]);
            // seq1左边序列产生了多少个逆序
            sum += r1 - i + 1;
        }
        else {
            arr2.push_back(arr1[i++]);
        }
    }
    while (i <= r1) {
        arr2.push_back(arr1[i++]);
    }
    while (j <= r2) {
        arr2.push_back(arr1[j++]);
    }
    for (int k = 0; k <= r2 - l1; k++) {
        arr1[l1 + k] = arr2[k];
    }
    return;
}

void MergeSort(int start, int end) {
    if (start >= end)return;
    int mid = (end + start) / 2;
    MergeSort(start, mid);
    MergeSort(mid + 1, end);
    Merge(start, mid, mid + 1, end);
    return;
}

int main(int argc, const char* argv[])
{
    int m, n, k;
    cin >> m;
    while (m--)
    {
        cin >> n;
        arr1.clear();
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> k;
            arr1.push_back(k);
        }
        MergeSort(0, n - 1);
        cout << sum << endl;
    }
    return 0;
}
