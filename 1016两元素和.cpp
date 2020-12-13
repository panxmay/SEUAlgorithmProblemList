#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#define INF 0X7FFFFFFF
using namespace std;

vector<int> arr,dp;
unordered_map<int, int> hs;

int main(int argc, const char* argv[])
{
    int m, n, k, temp, max;
    bool flag;
    cin >> m;
    while (m--)
    {
        cin >> n >> k;
        max = 0;
        flag = 0;
        hs.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            if (hs.find(temp) == hs.end())
                hs[k - temp] = temp;
            else flag = 1;
        }
        cout << (flag?"yes":"no") << endl;
    }
    return 0;
}
