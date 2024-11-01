#include<iostream>
#include<cstdio>
using namespace std;
int n,b[15][10],ans;//DCHS
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char c1,c2;
        cin>>c1>>c2;
        int x1,x2;
        if(c1=='D') x1=0;
        else if(c1=='C') x1=1;
        else if(c1=='H') x1=2;
        else if(c1=='S') x1=3;
        if(c2>='2'&&c2<='9') x2=c2-'0';
        else if(c2=='A') x2=1;
        else if(c2=='T') x2=10;
        else if(c2=='J') x2=11;
        else if(c2=='Q') x2=12;
        else if(c2=='K') x2=13;
        b[x2][x1]++;
    }
    for(int i=1;i<=13;i++)
        for(int j=0;j<=3;j++)
            if(b[i][j]==0)
                ans++;
    printf("%d",ans);
    return 0;
}
