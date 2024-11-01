#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t!=0)
    {
        int n,m,k,ans[t+1]={0};
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        char a[n+1][m+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        while(k!=0)
        {
            if(d0==0)
            {
                if(a[x0][y0+1]=='.')
                {
                    y0+=1;
                    ans[t]++;
                    k--;
                }
                if(a[x0][y0+1]=='x' || y0+1>m) d0=(d0+1)%4;
            }
            if(d0==1)
            {
                if(a[x0+1][y0]=='.')
                {
                    x0+=1;
                    ans[t]++;
                    k--;
                }
                if(a[x0+1][y0]=='x' || x0+1>n) d0=(d0+1)%4;
            }
            if(d0==2)
            {
                if(a[x0][y0-1]=='.')
                {
                    y0-=1;
                    ans[t]++;
                    k--;
                }
                if(a[x0][y0-1]=='x' || y0-1<m) d0=(d0+1)%4;
            }
            if(d0==0)
            {
                if(a[x0-1][y0]=='.')
                {
                    y0-=1;
                    ans[t]++;
                    k--;
                }
                if(a[x0-1][y0]=='x' || x0-1<n) d0=(d0+1)%4;
            }
        }

        t--;
    }
    for(int i=t;i>=1;i--)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}
