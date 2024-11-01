#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,xa[5]={0,1,0,-1},ya[5]={1,0,-1,0},cnt;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cnt=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int ii=1;ii<=n;ii++)
            for(int jj=1;jj<=m;jj++)
                cin>>a[ii][jj];
        for(int j=1;j<=k;j++)
        {
            if(a[x+xa[d]][y+ya[d]]!='x'&&x+xa[d]>=1&&x+xa[d]<=n&&y+ya[d]>=1&&y+ya[d]<=m)
            {
                a[x][y]='@';
                x+=xa[d];
                y+=ya[d];
                if(a[x][y]!='@') cnt++;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
