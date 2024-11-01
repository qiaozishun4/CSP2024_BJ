#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,a[200005],v[200005],as;
void dfs(int x,int s)
{
    int i,f1=0,f2=0;
    if(x>n)
    {
        as=max(as,s);
        return;
    }
    i=x;
    while(i>1)
    {
        i--;
        if(v[i]==1)
        {
            if(a[x]==a[i])
                f1=1;
            break;
        }
    }
    i=x;
    while(i>1)
    {
        i--;
        if(v[i]==2)
        {
            if(a[x]==a[i])
                f2=1;
            break;
        }
    }
    if(f1==1)
    {
        v[x]=1;
        dfs(x+1,s+a[x]);
    }
    else
    {
        v[x]=1;
        dfs(x+1,s);
    }
    if(f2==1)
    {
        v[x]=2;
        dfs(x+1,s+a[x]);
    }
    else
    {
        v[x]=2;
        dfs(x+1,s);
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;as=0;
        for(i=1;i<=n;i++)
            cin>>a[i];
        dfs(1,0);cout<<as<<endl;
    }
    return 0;
}
