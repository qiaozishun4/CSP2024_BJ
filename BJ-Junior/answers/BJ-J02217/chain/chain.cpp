#include<iostream>
#include<cstring>
#include<vector>
#define pii pair<int,int>
using namespace std;
int t,n,k,q,l,x,r,c;
vector<int>s[100010];
vector<pii >d[200010];
int dp[110][200010];
int hv[200010];
int main()
{
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        memset(hv,0,sizeof(hv));
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=100010;i++)
            s[i].erase(s[i].begin(),s[i].end());
        for(int i=1;i<=200010;i++)
            d[i].erase(d[i].begin(),d[i].end()),dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
                cin>>x,s[i].push_back(x),d[x].push_back({i,s[i].size()}),hv[x]=1;
        }
        for(int i=1;i<=110;i++)
        {
            for(int j=1;j<=200010;j++)
            {
                if(!hv[j])
                    continue;
                for(int p=0;p<d[j].size();p++)
                {
                    pii u=d[j][p];
                    int a=u.first;
                    int b=u.second;
                    for(int m=max(0,b-k+1);m<b;m++)
                    {
                        if(dp[i-1][s[a][m]]==-1)
                            continue;
                        if(dp[i-1][s[a][m]]==0||dp[i-1][s[a][m]]!=a)
                            if(dp[i][j]==-1)
                                dp[i][j]=i;
                            else
                                dp[i][j]=0;
                        if(dp[i][j]==0)
                            break;
                    }
                    if(dp[i][j]==0)
                        break;
                }
            }
        }
        while(q--)
        {
            cin>>r>>c;
            if(dp[r][c]!=-1)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}
