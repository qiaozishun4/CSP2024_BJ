#include<iostream>
using namespace std;
int mu[100010],mi[100010];
int u[20]={6,2,5,5,4,5,6,3,7,6};
int n,x,t,shu[100010];
bool dfs(int s,int sum)
{
    if(mu[t-s+1]+sum<x)
        return false;
    if(mi[t-s+1]+sum>x)
        return false;
    if(s>t&&sum==x)
        return true;
    if(s>t)
        return false;
    if(s!=1)
    {
        shu[s]=0;
        if(dfs(s+1,sum+u[0]))
            return true;
    }
    for(int i=1;i<=8;i++)
    {
        if(i==3||i==5)
            continue;
        shu[s]=i;
        if(dfs(s+1,sum+u[i]))
            return true;
    }
    return false;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=1;i<=100010;i++)
        mu[i]=i*7,mi[i]=i*2;
    cin>>n;
    while(n--)
    {
        cin>>x;
        t=(x-1)/7+1;
        if(dfs(1,0))
            for(int i=1;i<=t;i++)
                cout<<shu[i];
        else
            cout<<-1;
        cout<<endl;
    }
    return 0;
}
