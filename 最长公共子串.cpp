#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
bool table[505][505];
bool flag[505][505];


int LCS(const string s1, const string s2){
    int k=0;
    memset(table, 0, sizeof(table));
    memset(flag, 0, sizeof(flag));
    for(int i=0;i<s1.length();++i){
        for (int j=0;j<s2.length();++j){
            if (s1[i]==s2[j]){
                table[i][j] = 1;
                flag[i][j] = 1;
            }
        }
    }
    while (k<min(s1.length(),s2.length())){
        bool book=1;
        for(int i=0;i<s1.length();++i){
            if (i+k>=s1.length())break;
            for (int j=0;j<s2.length();++j){
                if (j+k>=s2.length())break;
                table[i][j] = table[i][j]&&flag[i+k][j+k];
                if (table[i][j])book=0;
            }
        }
        if (book)break;
        ++k;
    }
    return k;
}

/*
 2
 abcdefg
 cemg
 abcdefgh
 ceaaegh
 */



int main(int argc, const char * argv[]) {
    int m;
    string s1,s2;
    cin>>m;
    while(m--){
        cin>>s1>>s2;
        cout<<LCS(s1, s2)<<endl;
    }
    return 0;
}
