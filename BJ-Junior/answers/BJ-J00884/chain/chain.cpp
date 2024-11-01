#include<bits/stdc++.h>
using namespace std;
int n,k,q,l[100010],a[10010][20010];
bool flag=0;
void dfs(int last,int step,int c,int sum)
{
    if(sum==1)
    {
        for(int i=1;i<=l[step];i++)
        {
            if(a[step][i]==last)
            {
                for(int j=i+1;j<=min(l[step],i+k-1);j++)
                {
                    if(a[step][j]==c)
                    {
                        flag=1;
                        return;
                    }
                }
            }
        }
        return;
    }
    for(int i=1;i<=l[step];i++)
        {
            if(a[step][i]==last)
            {
                for(int j=i+1;j<=min(l[step],i+k-1);j++)
                {
                    for(int x=1;x<=n;x++)
                    {
                        if(x==step) continue;
                        dfs(a[step][j],x,c,sum-1);
                    }
                }
            }
        }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int h=1;h<=T;h++)
    {
        flag=0;
        memset(a,0,sizeof(0));
        memset(l,0,sizeof(0));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            int r,c;
            cin>>r>>c;
            for(int j=1;j<=n;j++)
            {
                dfs(1,j,c,r);
            }
            if(flag==1)
            {
                cout<<"1"<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
            flag=0;
        }
    }
    return 0;
}
