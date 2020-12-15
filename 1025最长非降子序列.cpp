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


int MaxSubSeq(int n) {
    int max = 1;
    arr2.push_back(1);
    for (int i = 1; i < n; i++) {
        int j = i;
        //max每次都需要初始化为1，否则会出错
        max = 1;
        while (j--) {
            if (arr1[j] <= arr1[i]) {
                max = (max > arr2[j] + 1 ? max : arr2[j] + 1);
            }
        }
        arr2.push_back(max);
    }
    for (int i = 0; i < n; i++) {
        if (arr2[i] > max)
            max = arr2[i];
    }
    return max;
}


/*
* 增加机组特殊的测试样例
10
7
2 4 6 3 4 5 6
4
1 3 2 4
9
4 1 7 3 2 3 5 7 6
5 
1 1 1 1 1 
5
9 8 7 6 5
5 
1 2 3 4 5
*/

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
        cout << MaxSubSeq(n)<< endl;
    }
    return 0;
}
