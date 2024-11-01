#include<bits/stdc++.h>
using namespace std;
int n,k;
char a[3];
int b[10][100];
int main()
{
   freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            int x,y;
        cin>>a[1]>>a[2];
        if(a[1]=='D') x=1;
        if(a[1]=='C') x=2;
        if(a[1]=='H') x=3;
        if(a[1]=='S') x=4;

        if(a[2]=='A') y=1;
        if(a[2]=='2') y=2;
        if(a[2]=='3') y=3;
        if(a[2]=='4') y=4;
        if(a[2]=='5') y=5;
        if(a[2]=='6') y=6;
        if(a[2]=='7') y=7;
        if(a[2]=='8') y=8;
        if(a[2]=='9') y=9;
        if(a[2]=='T') y=10;
        if(a[2]=='J') y=11;
        if(a[2]=='Q') y=12;
        if(a[2]=='K') y=13;
        b[x][y]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!b[i][j]){
                k++;
            }
        }
    }
    cout<<k;
    return 0;
}
