#include <iostream>
#include <cstring>
using namespace std;
int t;
int n,k,q;
int r,c;
int a[100005][100005];
bool dp[105][200005];
int da,xiao;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        cin >> n >> k >> q;
        da=0;
        xiao=300000;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i][0];
            for(int j=1;j<=a[i][0];j++)
            {
                cin >> a[i][j];
                da=max(da,a[i][j]);
                xiao=min(xiao,a[i][j]);
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin >> r >> c;
            memset(dp,0,sizeof(dp));
            dp[0][1]=true;
            int used=0;
            for(int j=1;j<=r;j++)
            {
                for(int w=xiao;w<=da;w++)
                {
                    bool ff=false;
                    for(int i1=1;i1<=n;i1++)
                    {
                        if(i1==used)
                        {
                            continue;
                        }
                        for(int j1=1;j1<=a[i1][0];j1++)
                        {
                            if(a[i1][j1]==w)
                            {
                                for(int j2=j1;j1-j2+1<=k&&j2>=1;j2--)
                                {
                                    if(dp[j-1][a[i1][j2]])
                                    {
                                        dp[j][w]=true;
                                        ff=true;
                                        used=i1;
                                        break;
                                    }
                                }
                            }
                            if(ff) break;
                        }
                        if(ff) break;
                    }
                }
            }
            if(dp[r][c])
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
