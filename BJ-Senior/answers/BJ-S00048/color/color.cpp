#include<bits/stdc++.h>
using namespace std;
int n;
int a[20005];
int lst[2];
bool now[20005];
int ans;
int tmp;
void dfs(int i)
{
    if(i==n+1)
    {
        //cout<<tmp<<" ";
        ans=max(tmp,ans);
        return ;
    }
    if(a[lst[0]]==a[i])tmp+=a[i];
    int k=lst[0];
    lst[0]=i;
    now[i]=0;
    dfs(i+1);
    lst[0]=k;
    if(a[lst[0]]==a[i])tmp-=a[i];
    if(a[lst[1]]==a[i])tmp+=a[i];
    k=lst[1];
    lst[1]=i;
    now[i]=1;
    dfs(i+1);
    lst[1]=k;
    if(a[lst[1]]==a[i])tmp-=a[i];
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
        cout<<ans<<endl;
    }
    return 0;
}
