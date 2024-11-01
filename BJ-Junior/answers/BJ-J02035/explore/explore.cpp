#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
short mark[1002][1002];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>> t;
    while(t--)
    {
        int n, m, k, i, j, x, y, d, cnt=1;
        string s;
        memset(mark,0,sizeof(mark));
        cin>> n >> m >> k >> x >> y >> d;
        for(i=1;i<=n;i++)
        {
            cin>> s;
            for(j=0;j<m;j++)
            {
                if(s[j]=='x')
                {
                    mark[i][j+1]=2;
                }
            }
        }
        mark[x][y]=1;
        for(i=1;i<=k;i++)
        {
            int x1,y1;
            x1=x+dx[d];
            y1=y+dy[d];
            if(mark[x1][y1]!=2 && (x1>0 && x1<=n) && (y1>0 && y1<=m))
            {
                if(mark[x1][y1]!=1)
                {
                    cnt++;
                }
                mark[x1][y1]=1;
                x=x1;
                y=y1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<< cnt << endl;
    }
    return 0;
}
