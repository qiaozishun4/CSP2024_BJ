#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
char a[N][N];
bool e[N][N];
int ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        ans=0;
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d;
        cin>>x0>>y0>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                e[i][j]=false;
        e[x0][y0]=true;
        for(int i=1;i<=k;i++)
        {
            d%=4;
            if(d==0)
            {
                if(a[x0][y0+1]=='.')
                {
                    y0++;
                    e[x0][y0]=true;
                }
                else
                {
                    d++;
                    i++;
                }
            }
            if(i>k)continue;
            if(d==1)
            {
                if(a[x0+1][y0]=='.')
                {
                    x0++;
                    e[x0][y0]=true;
                }
                else
                {
                    d++;
                    i++;
                }
            }
            if(i>k)continue;
            if(d==2)
            {
                if(a[x0][y0-1]=='.')
                {
                    y0--;
                    e[x0][y0]=true;
                }
                else
                {
                    d++;
                    i++;
                }
            }
            if(i>k)continue;
            if(d==3)
            {
                if(a[x0-1][y0]=='.')
                {
                    x0--;
                    e[x0][y0]=true;
                }
                else
                {
                    d++;
                    i++;
                }
            }
            if(i>k)continue;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(e[i][j]==true)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
