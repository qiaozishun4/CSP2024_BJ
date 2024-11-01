#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int v[10]={6,2,5,5,4,5,6,3,7,6};
string minn;
void dfs(int sum,string vv)
{
    if(sum==0)
    {
        if(minn.size()==vv.size())minn=min(minn,vv);
        else minn=minn.size()>vv.size()?vv:minn;
    }
    if(vv.empty())
    {
        for(int i=1;i<10;i++)
        {
            if(sum>=v[i])
            {
                vv.push_back(i+'0');
                dfs(sum-v[i],vv);
                vv.pop_back();
            }
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(sum>=v[i])
            {
                vv.push_back(i+'0');
                dfs(sum-v[i],vv);
                vv.pop_back();
            }
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    string x;
    for(int i=0;i<=11111;i++)x.push_back('9');
    cin>>t;
    while(t--)
    {
        minn=x;
        cin>>n;
        dfs(n,string());
        if(minn!=x)cout<<minn<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
