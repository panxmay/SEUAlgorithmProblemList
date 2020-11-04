#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;


int KnapsackProblemTwo(const int n, const int v1, const int v2, const vector<int>& weights, const vector<int>& values) {
	// 初始化状态
	vector<vector<vector<int>>> table(n + 1, vector<vector<int>>(v1 + 1, vector<int>(v2 + 1, 0)));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= v1; ++j) {
			for (int k = 1; k <= v2; ++k) {
				table[i][j][k] = max(table[i - 1][j][k], max(j >= weights[i] ? table[i - 1][j - weights[i]][k] + values[i] : 0, k >= weights[i] ? table[i - 1][j][k - weights[i]] + values[i] : 0));
			}
		}
	}
	return table[n][v1][v2];
}


int KnapsackProblemM(const int n, const int v, const int m, const vector<int>& weights, const vector<int>& values) {
	// 初始化状态
	vector<vector<vector<int>>> table(n + 1, vector<vector<int>>(v + 1, vector<int>(m + 1, 0)));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= v; ++j) {
			for (int k = 1; k <= m; ++k) {
				table[i][j][k] = max(table[i - 1][j][k], j >= weights[i] ? table[i - 1][j - weights[i]][k - 1] + values[i] : 0);
			}
		}
	}
	return table[n][v][m];
}

int KnapsackProblemFull(const int n, const int v, const vector<int>& weights, const vector<int>& values) {
	// 初始化状态
	vector<vector<int>> table(n + 1, vector<int>(v + 1, -1));
	for (int i = 0; i <= n; ++i) table[i][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (j < weights[i] || table[i - 1][j - weights[i]] == -1) table[i][j] = table[i - 1][j];
			else table[i][j] = max(table[i - 1][j], table[i - 1][j - weights[i]] + values[i]);
		}
	}
	return table[n][v];
}

int KnapsackProblem01(const int n, const int v, const vector<int>& weights, const vector<int>& values) {
	// 初始化状态
	vector<vector<int>> table(n + 1, vector<int>(v + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= v; ++j) {
			table[i][j] = max(table[i - 1][j], j >= weights[i] ? table[i - 1][j - weights[i]] + values[i] : 0);
		}
	}
	return table[n][v];
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


