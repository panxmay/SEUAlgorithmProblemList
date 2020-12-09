#include <iostream>
#include <cstring>
using namespace std;
int C[10005];
int prices[100005];
int max_index = 0;

int RobCutting(const int n)
{
    for (int i = 1; i <= n; ++i)
    {
        int max_value = 0;
        for (int j = 1; j <= i; ++j)
        {
            int temp = prices[j] + C[i - j];
            if (temp > max_value)max_value = temp;
        }
        C[i] = max_value;
    }
    return C[n];
}


int main(int argc, const char* argv[])
{
    int m, n, k;
    cin >> m;
    while (m--)
    {
        cin >> n >> k;
        memset(prices, 0, sizeof(prices));
        memset(C, 0, sizeof(C));
        while (k--)
        {
            int temp;
            cin >> temp >> prices[temp];
            if (temp > max_index)max_index = temp;
        }
        cout << RobCutting(n) << endl;
    }
    return 0;
}
