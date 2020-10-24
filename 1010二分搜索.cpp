#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num--) {
        int N,X;
        int arr[20001];
        cin >> N >> X;
        for (auto i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int low = 0, high = N - 1;
        int father = arr[0];
        bool flag = 0;
        while (low <= high) {
            if (arr[(low + high) / 2] == X) {
                flag = 1;
                break;
            }
            else {
                father = arr[(low + high) / 2];
                if (arr[(low + high) / 2] < X) {
                    low = (low + high) / 2 + 1;
            }
                else {
                    high = (low + high) / 2 - 1;
                }
            }    
        }
        printf("%s father is %d \n", flag ? "success," : "not found,", father);
    }
    return 0;
}


