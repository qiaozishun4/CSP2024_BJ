#include<bits/stdc++.h>
using namespace std;
int p[13][4]={ };
char a,b;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>a>>b;
        if(a=='D') y=0;
        if(a=='c') y=1;
        if(a=='H') y=2;
        if(a=='S') y=3;
        if(b=='A') x=0;
        if(b==2) x=1;
        if(b==3) x=2;
        if(b==4) x=3;
        if(b==5) x=4;
        if(b==6) x=5;
        if(b==7) x=6;
        if(b==8) x=7;
        if(b==9) x=8;
        if(b=='T') x=9;
        if(b=='J') x=10;
        if(b=='Q') x=11;
        if(b=='K') x=12;
        p[x][y]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(p[j][i]==0) sum++;
        }
    }
    cout<<sum;
    return 0;
}
