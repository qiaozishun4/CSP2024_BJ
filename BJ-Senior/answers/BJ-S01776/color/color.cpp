#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int color[200010];
int ans=-1;
void dfs(int dep)
{
    if(dep==n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(color[i]==color[j])
                {
                    if(a[i]==a[j])
                    {
                        sum+=a[i];
                    }
                }
            }
        }
        ans=max(sum,ans);
        return ;
    }
    color[dep]=1;
    dfs(dep+1);
    color[dep]=2;
    dfs(dep+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ans=0;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}