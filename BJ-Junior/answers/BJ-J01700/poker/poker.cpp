#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
long long n,num,ans;
bool flag[100][1000];
char a[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf ("%lld", &n);
    for (int i=1;i<=n;i++){
        cin>>a;
        if (a[1]>='0'&&a[1]<='9') num = a[1]-'0';
        if (a[1]=='A') num = 1;
        if (a[1]=='T') num = 10;
        if (a[1]=='J') num = 11;
        if (a[1]=='Q') num = 12;
        if (a[1]=='K') num = 13;
        if (a[0]=='D') flag[1][num] = true; //DCHS
        if (a[0]=='C') flag[2][num] = true;
        if (a[0]=='H') flag[3][num] = true;
        if (a[0]=='S') flag[4][num] = true;
    }
    for (int i=1;i<=4;i++){
        for (int j=1;j<=13;j++) if (flag[i][j]==false) ans+=1;
    }
    printf ("%d\n", ans);
    return 0;
}
