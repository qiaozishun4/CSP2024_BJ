#include<bits/stdc++.h>
using namespace std;
int a[20],ans,n,b[20];
void dfs(int step)
{
    if(step>n)
    {
        int t=0;
        for(int i=1;i<=n;i++)
        {
            int j=i-1;
            while(b[i]!=b[j]&&j>=1)j--;
            if(a[i]==a[j])t+=a[i];
        }
        ans=max(ans,t);
        return;
    }
    b[step]=0;
    dfs(step+1);
    b[step]=1;
    dfs(step+1);
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
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}