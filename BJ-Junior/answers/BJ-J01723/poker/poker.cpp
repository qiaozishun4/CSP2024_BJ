#include<bits/stdc++.h>
using namespace std;
const string x = "$DCHS", y = "$A23456789TJQK";
bool poker[14][5];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    memset(poker, true, sizeof(poker));
    int n;
    cin>>n;
    string pokeri;
    for(int i = 1;i <= n;i++){
        cin>>pokeri;
        string sub1 = pokeri.substr(0, 1);
        string sub2 = pokeri.substr(1, 1);
        poker[y.find(sub2)][x.find(sub1)] = 0;
    }
    int cnt = 0;
    for(int i = 1;i <= 14;i++)
        for(int j = 1;j <= 4;j++)
            cnt += poker[i][j];
    cout<<cnt;
    return 0;
}