#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <stdio.h>
#define INF 0X7FFFFFFF
using namespace std;

//控制精度
const double ZERO = 1e-10;

//定义结构体数组,vector会超时
struct Node {
    int l,r;
} a[100001], temp[100001];

double ans = 0.0;

bool compareX(Node a, Node b)
{//自定义排序规则：依照结构体中的x成员变量升序排序
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}

bool compareY(Node a, Node b)
{//自定义排序规则：依照结构体中的x成员变量升序排序
    return a.r < b.r;
}


double Distance(Node a, Node b) {
    return sqrt(1.0 * (a.l - b.l) * (a.l - b.l) + 1.0 * (a.r - b.r) * (a.r - b.r));
}

/*
10
10
7 9
-8 -1
-3 -1
1 4
-3 9
6 -4
7 5
6 6
-6 10
0 8
*/


double Solution(int start,int end) {
    //如果只有一个点,则标记为不可达
    if (start >= end) {
        return INF;
    }
    //如果刚好只有两个点
    else if (start == end - 1) {
        return Distance(a[start], a[end]);
    }
    //如果超过三个点,则分治处理
    else {
        double dis, d1, d2;
        int mid = (start + end) / 2, mid_x = a[(start + end) / 2].l;
        d1 = Solution(start, mid);
        d2 = Solution(mid + 1, end);
        dis = min(d1, d2);
        //merge检查中线部分是否存在最近点
        int k = 0;
        for (int i = start; i <= end; i++) {
            if (a[i].l > mid_x - dis && a[i].l < mid_x + dis) {
                temp[k].l = a[i].l;
                temp[k].r = a[i].r;
                k++;
            }
        }
        //sort(temp, temp + k, compareY);
        int x = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k && j <= i + 6; j++) {
                double ab = Distance(temp[i], temp[j]);
                dis = ab < dis ? ab : dis;
            }           
        }
        return dis;
    }  
}

int main(int argc, const char* argv[])
{
    int m, n, k, t;
    cin >> m;
    while (m--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> a[i].l >> a[i].r;
        }
        sort(a, a + n, compareX);
        printf("%.2f\n", Solution(0, n - 1));
    }
    return 0;
}

