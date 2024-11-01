#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a[60][60];
int b[60][60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=n;i++){
        int x;
        int y;
        if(a[i][1]=='D') x=1;
        if(a[i][1]=='C') x=2;
        if(a[i][1]=='H') x=3;
        if(a[i][1]=='S') x=4;
        if(a[i][2]>='2'&&a[i][2]<=9) {
            y=a[i][2]-'1';
        }
        if(a[i][2]=='A') y=1;
        if(a[i][2]=='T') y=10;
        if(a[i][2]=='J') y=11;
        if(a[i][2]=='Q') y=12;
        if(a[i][2]=='K') y=13;
        b[x][y]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]!=0) ans++;
        }
    }
    cout<<52-ans;
    return 0;
}
