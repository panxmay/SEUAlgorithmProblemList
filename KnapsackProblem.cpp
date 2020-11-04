#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;


int KnapsackProblemTwo(int N, int V1, int V2, vector<int> weights, vector<int> values) {
    //初始化状态
    vector<vector<vector<int>>> table(N + 1, vector<vector<int>>(V1 + 1, vector<int>(V2 + 1, 0)));
    for (auto i = 1; i <= N; i++) {
        for (auto j = 1; j <= V1; j++) {
            for (auto k = 1; k <= V2; k++) {
                table[i][j][k] = max(table[i - 1][j][k], max(j >= weights[i] ? table[i - 1][j - weights[i]][k] + values[i] : 0, k >= weights[i] ? table[i - 1][j][k - weights[i]] + values[i] : 0));
            }
        }
    }
    return table[N][V1][V2];
}


int KnapsackProblemM(int N, int V, int M, vector<int> weights, vector<int> values) {
    //初始化状态
    vector<vector<vector<int>>> table(N + 1, vector<vector<int>>(V + 1, vector<int>(M + 1, 0)));
    for (auto i = 1; i <= N; i++) {
        for (auto j = 1; j <= V; j++) {
            for (auto k = 1; k <= M; k++) {
                table[i][j][k] = max(table[i - 1][j][k], j >= weights[i] ? table[i - 1][j - weights[i]][k - 1] + values[i] : 0);
            }
        }
    }
    return table[N][V][M];
}

int KnapsackProblemFull(int N, int V, vector<int> weights, vector<int> values) {
    //初始化状态
    vector<vector<int>> table(N + 1, vector<int>(V + 1, -1));
    for (auto i = 0; i <= N; i++)table[i][0] = 0;
    for (auto i = 1; i <= N; i++) {
        for (auto j = 1; j <= V; j++) {
            if (j < weights[i] || table[i - 1][j - weights[i]] == -1)table[i][j] = table[i - 1][j];
            else table[i][j] = max(table[i - 1][j], table[i - 1][j - weights[i]] + values[i]);
        }
    }
    return table[N][V];
}

int KnapsackProblem01(int N, int V, vector<int> weights, vector<int> values) {
    //初始化状态
    vector<vector<int>> table(N + 1, vector<int>(V + 1, 0));
    for (auto i = 1; i <= N; i++) {
        for (auto j = 1; j <= V; j++) {
            table[i][j] = max(table[i - 1][j], j >= weights[i] ? table[i - 1][j - weights[i]] + values[i] : 0);
        }
    }
    return table[N][V];
}

int main()
{
    int N = 5;
    int V = 10;
    int M = 3;
    vector<int> weights = { 0,2,2,6,5,4 };
    vector<int> values = { 0,6,3,5,4,6 };
    cout << "01背包问题\n";
    cout << KnapsackProblem01(N, V, weights, values) << endl;
    cout << "限制装满的背包问题\n";
    cout << KnapsackProblemFull(N, V, weights, values) << endl;
    cout << "从N件物品中最多选取M件物品的背包问题\n";
    cout << KnapsackProblemM(N, V, min(N, M), weights, values) << endl;
    cout << "两个背包的背包问题\n";
    cout << KnapsackProblemTwo(N, V, V, weights, values) << endl;
    return 0;
}


