#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("explore.in","r",stdin);
    freopen ("explore.out","w",stdout);
    int T,n,m,k,x,y,d;
    string zfc;
    cin>>T;
    int shuchu;
    for(int i=0;i<T;i++)
    {
        shuchu=0;
        cin>>n>>m>>k;
        int a[n+1][m+1]={0};
        for(int j=0;j<n;j++)
            cin>>zfc;
        cin>>x>>y>>d;
        a[y][x]=1;
        for(int j=0;j<k;j++)
        {
            a[y][x]=1;
            if(d==0)
            {
                if(y==m)
                    d++;
                else
                {
                    y++;
                    a[y][x]=1;
                }
            }
            if(d==1)
            {
                if(x==n)
                    d++;
                else
                {
                    x++;
                    a[y][x]=1;
                }
            }
            if(d==2)
            {
                if(y==1)
                    d++;
                else
                {
                    y--;
                    a[y][x]=1;
                }
            }
            if(d==3)
            {
                if(x==1)
                    d=0;
                else
                {
                    x--;
                    a[y][x]=1;
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=m;l++)
            {
                if(a[j][l]==1)
                    shuchu++;
            }
        }
        cout<<shuchu<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
