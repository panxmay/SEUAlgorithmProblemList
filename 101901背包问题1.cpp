#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int KnapsackProblem(const int n, const int v, const vector<int>& weights, const vector<int>& values) {
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
	int N,C,n;
	cin >> n;
	while (n--) {
		cin >> N >> C;
		vector<int> weights(N+1, 0);
		vector<int> values(N+1, 0);
		for (int i = 1; i <= N; i++) {

			cin >> weights[i] >> values[i];
		}
		cout << KnapsackProblem(N, C, weights, values) << endl;
	}
	return 0;
}


