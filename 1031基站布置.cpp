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

//控制精度
const double ZERO = 1e-10;

struct Node {
    //记录在x坐标轴上左右两端能覆盖的范围
    double l, r;
};

vector<Node> a;

vector<int> arr1,arr2;
vector<vector<int>>matrix;
int sum;

bool cmp(Node n1, Node n2) {
    return (n1.l == n2.l ? n1.r < n2.r : n1.l < n2.l);
}


int Solution(int n) {
    int ans = 1;
    double now = a[0].r;
    for (int i = 1; i < n; i++) {
        if (a[i].l > now + ZERO) {
            //下个点的最左被覆盖的坐标大于当前最右可被覆盖坐标
            ans++;
            now = a[i].r;
        }
        else if (a[i].r < now + ZERO)
        {
            //下个点的最左被覆盖的坐标小于当前最右可被覆盖坐标
            now = a[i].r;
        }

    }
    return ans;
}

int main(int argc, const char* argv[])
{
    int m, n, k, t;
    cin >> m;
    while (m--)
    {
        cin >> n >> k;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            double t;
            cin >> x >> y;
            t = sqrt((k * k - y * y));
            a[i].l = x - t;
            a[i].r = x + t;
        }
        sort(a.begin(), a.end(), cmp);
        cout << Solution(n) << endl;
    }
    return 0;
}

//https://blog.csdn.net/WilsonSong1024/article/details/79449536
