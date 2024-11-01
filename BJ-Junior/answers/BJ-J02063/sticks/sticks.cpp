#include<bits/stdc++.h>
using namespace std;
int n,t;
int d[10]={6,2,5,5,4,5,6,3,7,6};
bool f=0;
unsigned long long ans=1e18;
unsigned long long num;
void dfs(int s)
{
    if(s<0)return;
    if(num>ans)return;
    if(s==0)
    {
        f=1;
        ans=min(num,ans);
        return;
    }
    for(int i=0;i<=9;i++)
    {
        if(num==0&&i==0)continue;
        else
        {
            if(s>=d[i])
            {
                num=num*10+i;
                dfs(s-d[i]);
                num/=10;
            }
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        f=0;
        ans=1e18;
        num=0;
        cin>>n;
        if(n==0)
        {
            cout<<-1<<endl;
            continue;
        }
        dfs(n);
        if(f==1)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
