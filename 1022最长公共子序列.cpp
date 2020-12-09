#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
int table[505][505];

int LCS(const string& s1, const string& s2){
    memset(table, 0, sizeof(table));
    for(int i=1;i<=s2.length();++i){
        for(int j=1;j<=s1.length();++j){
            if ((table[i][j-1]-table[i-1][j-1]==1)||(table[i-1][j]-table[i-1][j-1]==1) || s2[i-1]!=s1[j-1]){
                table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
            else {
                table[i][j] = max(table[i-1][j],table[i][j-1])+1;
            }
        }
    }
    return table[s2.length()][s1.length()];
}

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

