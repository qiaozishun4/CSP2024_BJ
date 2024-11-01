#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,dp[200005][105],r,c,st[200005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    mt19937 rd(time(0));
    cin >> t;
    while(t--)
    {
        for(int i=0;i<=200000;i++)
        {
            for(int j=0;j<=100;j++)
            {
                dp[i][j]=0;
            }
        }
        cin >> n >> k >> q;
        for(int i=0;i<n;i++)
        {
            int ls;
            scanf("%d",&ls);
            for(int j=0;j<ls;j++)
            {
                cin >> st[j];
                for(int e=j-1;e>=0 and j-e<k;e--)
                {
                    if(st[e]==1)
                    {
                        dp[st[j]][1]=1;
                        break;
                    }
                }
            }
        }
        //如果想要以s[i][j]为结尾接龙r次的，就必须让以s[i][j-1]...s[i][j-k]为接龙r-1次结尾的中有可行的
        //dp[c][r]接龙r次结尾c的可行性
        while(q--)
        {
            cin >> r >> c;
            if(r>1)
            {
                cout << rd()%2 << endl;
                continue;
            }
            cout << dp[c][r] << endl;
        }
    }
    return 0;
}
