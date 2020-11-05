#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int m;
	cin >> m;
	while (m--) {
		int n, min = 1001, sec_min = 1001;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i]<sec_min && arr[i]>min) {
				sec_min = arr[i];
			}
		}
		cout << sec_min<<endl;
	}

	return 0;
}


