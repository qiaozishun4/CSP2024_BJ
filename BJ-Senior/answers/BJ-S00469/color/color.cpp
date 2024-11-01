#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n;
int color[200005];
int box[200005];
long long ans;
void dfs(int x)
{
    if(x==n+1)
    {
        long long s=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(box[i]==box[j]&&a[i]!=a[j])
                {
                    break;
                }
                if(box[i]==box[j]&&a[j]==a[i])
                {
                    s+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,s);
        return ;
    }
    for(int i=0;i<=1;i++)
    {
        box[x]=i;
        dfs(x+1);
    }
    return ;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
