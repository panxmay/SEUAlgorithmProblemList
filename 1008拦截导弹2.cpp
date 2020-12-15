#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 0X7FFFFFFF
using namespace std;

vector<int> arr, dp, sys;

void DP(const int n) {
    sys.push_back(arr[0]);
    for (int i = 1; i < n; ++i) {
        int j = i, flag = -1;
        int max = 1, temp;
        while (j--) {
            if (arr[j] >= arr[i]) {
                //max = (dp[j] + 1) > max ? dp[j] + 1 : max;
                if ((dp[j] + 1) > max) {
                    max = dp[j] + 1;
                    flag = j;
                }
            }
        }
        dp[i] = max;
        if (flag == -1) {
            // 比前面所有导弹的高度都更高
            sys.push_back(arr[i]);
            continue;
        }
        //监测是否是前面某一个系统能够拦截的高度
        bool book = 1;
        for (auto& item : sys) {
            if (item == arr[flag]) {
                item = arr[i];
                //和max找到的拦截系统完全匹配
                book = 0;
            }
        }
        if (book) {
            // 能够被某个系统拦截，但肯定不是“主线系统”
            int k = -1, min = INF;
            for (int x = 0; x < sys.size(); x++) {
                // 找到最低高度与当前导弹高度最近的“支线系统”将其拦截
                if (arr[i] < sys[x] && sys[x] - arr[i] < min) {
                    //有一个“支线系统”将其拦截
                    min = sys[x] - arr[x];
                    k = x;
                }
            }
            // 没有找到“支线系统”将其拦截，因此需要增加一个系统
            if (k == -1)sys.push_back(arr[i]);
            else sys[k] = arr[i];
        };

        /*
        if (flag == -1) {
            sys.push_back(arr[i]);
            continue;
        }
        bool book = 1;
        for (auto& item : sys) {
            if (item == arr[flag]) {
                item = arr[i];
                book = 0;
            }
        }
        if (book)sys.push_back(arr[i]);
        */
        
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
        sys.clear();
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
        cout << max << " " << sys.size() << endl;
    }
    return 0;
}
