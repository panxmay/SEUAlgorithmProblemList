#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    getchar();
    for (auto i = 0; i < num; i++) {
        char s[101];
        int count = 0;
        cin.getline(s, 101);
        for (auto i = 0; i < strlen(s); i++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}


