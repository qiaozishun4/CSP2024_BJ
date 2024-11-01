#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int cnt[N];
int mp[N][N];
int dp[N][N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof(cnt));
            vector<int> v;
            int l;
            scanf("%d",&l);
            for(int i=1;i<=l;i++)
            {
                int c;
                scanf("%d",&c);
                if(cnt[c]==0)
                {
                    cnt[c]=1;
                    v.push_back(c);
                }
            }
            for(int i=0;i<v.size();i++)
            {
                for(int j=i+1;j+k<v.size();j++)
                {
                    mp[i][j]=1;
                }
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(dp[i-1][j]==1)
                {
                    for(int k=1;k<=N;k++)
                    {
                        if(mp[j][k]==1)
                        {
                            dp[i][k]=1;
                        }
                    }
                }
            
            }
        }
        int flag=1;
        for(int i=1;i<=q;i++)
        {
            int r,c;
            scanf("%d%d",&r,&c);
            if(dp[r][c]==0)
            {
                flag=0;
            }
        }
        printf("%d",flag);
    }
    return 0;
}