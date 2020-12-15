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

string str;
vector<vector<long long int>> f;

long long int cut(int start, int end) {
    long long int sum = 0;
    for(int i = start; i <= end; ++i) {
        sum = sum * 10 + (str[i]-'0');
    }
    return sum;
}

int MaxProduct(int n, int k) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            long long int max = 0;
            for (int b = 0; b < i; b++) {
                int temp = f[b][j - 1] * cut(b + 1, i);
                if ( temp > max)
                    max = temp;
            }
            f[i][j] = max;
        }
    }
    return f[n - 1][k];
}


int main(int argc, const char* argv[])
{
    int m, n, k, sum;
    cin >> m;
    while (m--)
    {
        cin >> n >> k;                                                                                                                        
        cin >> str;
        f.clear();
        f.resize(n + 1, vector<long long int>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            f[i][0] = cut(0,i);
        }
        sum = MaxProduct(n, k);
        cout << sum << endl;
    }
    return 0;
}
