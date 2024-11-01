#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d[10]={6,2,5,5,4,5,6,3,7,6},ans=1e9;
void dfs(int num)
{
    if(n==0)
    {
        ans=min(ans,num);
        return;
    }
    if(n<0)
        return;
    if(num!=0)
    {
        n-=6;
        dfs(num*10);
        n+=6;
    }
    int i=num%10;
    if(i==0)i=1;
    for(;i<10;i++)
    {
        n-=d[i];
        dfs(num*10+i);
        n+=d[i];
    }
    return;
}
signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0||n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        dfs(0);
        cout<<ans<<endl;
        ans=1e9;
    }
    return 0;
}