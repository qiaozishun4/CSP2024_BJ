#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    bool dp[101][2005];
    int a[1001][1001];
    queue<int> qu[101];
    cin>>t;
    while(t--)
    {
        //dp[i][j]:zai di i lun,chu yi k wei jie wei de shu ke bu ke yi
        memset(dp,false,sizeof dp);
        int n,k,q,l[200001],r,c,x=-1;
        bool f=false;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            x=-1;
            for(int j=1;j<=l[i];j++)
            {
                cin>>a[i][j];
                if(a[i][j]==1)
                    x=j;
                if(x!=-1 && j-x+1<=k)
                {
                    dp[1][a[i][j]]=true;
                    qu[1].push(a[i][j]);
                }
            }
        }
        x=-1;/*
        for(int i=2;i<=101;i++)
        {
            while(!qu[i-1].empty())
            {
                for(int j=1;j<=n;j++)
                {
                    for(int kk=1;kk<=l[j];kk++)
                    {
                        if(a[j][kk]==qu[i-1].front())
                            x=j;
                        if(x!=-1 && kk-x+1<=k)
                        {
                            dp[i][a[j][kk]]=true;
                            qu[i].push(a[j][kk]);
                        }
                    }
                }
                qu[i-1].pop();
            }
        }*/
        for(int i=1;i<=q;i++)
        {
            f=false;
            cin>>r>>c;
            if(dp[r][c])
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}
