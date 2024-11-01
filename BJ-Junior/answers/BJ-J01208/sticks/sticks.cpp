#include<iostream>
#include<climits>
using namespace std;
int t,n,ans=INT_MAX;
int d[]={6,2,5,5,4,5,6,3,7,6};
void dfs(int num,int sum)
{
    if(num==n&&sum!=0)
    {
        ans=min(ans,sum);
        return;
    }
    if(sum>=ans)
    {
        return;
    }
    for(int i=0;i<=9;++i)
    {
        if(num+d[i]<=n)
        {
            if(sum==0&&i==0)
            {
                continue;
            }
            dfs(num+d[i],sum*10+i);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        dfs(0,0);
        if(ans==INT_MAX)
        {
            cout<<-1<<'\n';
        }
        else
        {
            cout<<ans<<'\n';
        }
        ans=INT_MAX;
    }
    return 0;
}
