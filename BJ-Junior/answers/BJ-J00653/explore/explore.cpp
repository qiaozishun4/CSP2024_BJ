#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k,x,y,d,sum=0,num[1001][1001]={0};
        char a[1001][1001]={'x'};
        cin >> n >> m >> k >> x >> y >> d;
        num[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i=0;i<k;i++)
        {
            if(d==0)
            {
                if(x>=1 && x<=n && y+1>=1 && y+1<=m && a[x][y+1]!='x')
                {
                    y++;
                    num[x][y]++;
                }
                else
                {
                    d=1;
                }
            }
            else if(d==1)
            {
                if(x+1>=1 && x+1<=n && y>=1 && y<=m && a[x+1][y]!='x')
                {
                    x++;
                    num[x][y]++;
                }
                else
                {
                    d=2;
                }
            }
            else if(d==2)
            {
                if(x>=1 && x<=n && y-1>=1 && y-1<=m && a[x][y-1]!='x')
                {
                    y--;
                    num[x][y]++;
                }
                else
                {
                    d=3;
                }
            }
            else if(d==3)
            {
                if(x-1>=1 && x-1<=n && y>=1 && y<=m && a[x-1][y]!='x')
                {
                    x--;
                    num[x][y]++;
                }
                else
                {
                    d=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(num[i][j]>=1)
                {
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
