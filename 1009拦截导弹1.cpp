#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 0X7FFFFFFF
using namespace std;

vector<int> arr,dp;

void DP(const int n) {
    for (int i = 1; i < n; ++i) {
        int j = i;
        int max = 1, temp;
        while (j--) {
            if (arr[j] >= arr[i]) {
                max = (dp[j] + 1) > max ? dp[j] + 1 : max;
            }
        }
        dp[i] = max;
    }
}

int main(int argc, const char* argv[])
{
    int m, n, k, temp, max;
    cin >> m;
    while (m--)
    {
        cin >> n;
        max = 0;
        arr.clear();
        dp.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            arr.push_back(temp);
            dp.push_back(1);
        }
        DP(n);
        for (int i = 0; i < n; i++) {
            max = dp[i] > max ? dp[i] : max;
        }
        cout << max << endl;
    }
    return 0;
}
