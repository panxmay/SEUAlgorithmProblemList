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
vector<vector<int>>matrix;
int sum;


bool Solution(int n, int k, int t) {
    int i = n - 1, j = 0;
    while (i >= 0 && j < k) {
        if (matrix[i][j] == t)return 1;
        else if (matrix[i][j] < t) {
            j++;
        }
        else {
            i--;
        }
    }
    return 0;
}


int main(int argc, const char* argv[])
{
    int m, n, k, t;
    cin >> m;
    while (m--)
    {
        cin >> n >> k >> t;
        matrix.clear();
        matrix.resize(n,vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << (Solution(n, k, t) ? "true" : "false") << endl;
    }
    return 0;
}
