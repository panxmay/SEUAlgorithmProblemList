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
int sum;


int MaxSubSum(int n) {
    int max = arr1[0];
    for (int i = 1; i < n; i++) {
        //有两种情况需要舍弃，当前数与前一个数的和为<0,或者到前一个数时最大子序列和已经<0;
        if (arr2[i - 1] + arr1[i] < 0 || arr2[i - 1] < 0) {
            arr2.push_back(arr1[i]);
        }
        else {
            arr2.push_back((arr2[i - 1] + arr1[i]));
        }
    }
    for (int i = 0; i < n; i++) {
        if (max < arr2[i]) {
            max = arr2[i];
        }
    }
    return max;
}

int main(int argc, const char* argv[])
{
    int m, n, k;
    cin >> m;
    while (m--)
    {
        cin >> n;
        arr1.clear();
        arr2.clear();
        for (int i = 0; i < n; i++) {
            cin >> k;
            arr1.push_back(k);
        }
        arr2.push_back(arr1[0]);
        cout << MaxSubSum(n)<< endl;
    }
    return 0;
}
