#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cstring>
#define INF 0x7fffffff
using namespace std;
int table[501][501];
struct matrix{
    int row;
    int col;
}A[501];

int MatrixChainMultipycation(const int n, matrix* A){
    memset(table,0,sizeof(table));
    for(int step=1;step<n;++step) {
        for (int i = 0; i < n; ++i) {
            int min = INF;
            int j=i+step;
            if(j>=n)
            {
                break;
            }
            for (int k = i; k < j && j < n; ++k) {
                int temp = table[i][k] + table[k + 1][j] + A[i].row * A[k].col * A[j].col;
                if (temp < min)min = temp;
            }
            table[i][j] = min;
        }
    }
    return table[0][n-1];
}


int main() {
    int n, m;
    cin>>n;
    while(n--){
        cin>>m;
        memset(A,0,sizeof(A));
        for (int i=0;i<m;++i) {
            cin >> A[i].row >> A[i].col;
        }
#if 0
        cout<<MatrixChainMultipycation(m,A);
#else
        cout<<MatrixChainMultipycation(m,A)<<endl;
#endif

    }
    return 0;
}
