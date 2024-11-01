#include <bits/stdc++.h>
using namespace std;
char c[1001][1001];
int X[4]={0,1,0,-1},Y[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,y,d,cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)cin>>c[i][j];
        c[x][y]='1';
        while(k--)
        {
            c[x][y]='1';
            int x2=x+X[d],y2=y+Y[d];
            if(x2>=1&&x2<=n&&y2>=1&&y2<=m&&c[x2][y2]!='x')x=x2,y=y2;
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)if(c[i][j]=='1')cnt++;
        cout<<cnt<<endl;
    }
}