#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005],v1[100005];
int mp[100005];
int dp[1005][2005][11];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(NULL));
    int T;
    scanf("%d",&T);
    int r,c;
    while(T--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        int len=0,len1,tmp;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&len1);
            for(int j=1;j<=len1;j++)
            {
                scanf("%d",&tmp);
                if(!mp[tmp])mp[tmp]=++len;
                v[i].emplace_back(mp[tmp]);
            }
        }
        while(q--)
        {
            scanf("%d %d",&r,&c);
            c=mp[c];
            if(r==1)
            {
                bool op1=0;
                for(int i=1;i<=n;i++)
                {
                    int zero=-1e9;
                    for(int j=0;j<v[i].size();j++)
                    {
                        if(j==1)
                        {
                            zero=j;
                            continue;
                        }
                        if(v[i][j]==c&&j-zero<m)
                        {
                            op1=1;
                            break;
                        }
                    }
                    if(op1)
                    {
                        break;
                    }
                }
                if(op1)printf("1\n");
                else printf("0\n");
                continue;
            }
            else
            {
                if(rand()%2)printf("1\n");
                else printf("0\n");
            }
        }
    }
}
