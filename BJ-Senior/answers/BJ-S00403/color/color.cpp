#include<bits/stdc++.h>
using namespace std;

int n,a[30],ans,d[30];

void dfs(int x)
{
    if(x>n)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            int p=i-1;
            while(true)
            {
                if(p<1)
                    break;
                if(d[p]==d[i])
                {
                    if(a[p]==a[i])
                        num+=a[p];
                    break;
                }
                p--;
            }
        }
        ans=max(ans,num);
        return ;
    }
    dfs(x+1);
    d[x]=1;
    dfs(x+1);
    d[x]=0;
    return ;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(d,0,sizeof(d));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
