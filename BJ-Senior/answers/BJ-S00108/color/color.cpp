#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
int a[200005],co[200005],c[200005],n,ans=-1,t;
void dfs(int x,int kind)
{
    if(x<0)
    {
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0&&co[j]!=co[i])
            {
                j--;
            }
            if(j!=-1)
            {
                if(a[j]==a[i])
                {
                    c[i]=a[i];
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=c[i];
        }
        ans=max(ans,cnt);
        return;
    }
    if(kind==1)
    {
        co[x]=1;
    }
    if(kind==2)
    {
        co[x]=2;
    }
    dfs(x-1,1);
    dfs(x-1,2);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        dfs(n,1);
        dfs(n,2);
        cout<<ans<<endl;
        ans=-1;
        memset(c,0,sizeof(c));
        memset(co,0,sizeof(co));
        memset(a,0,sizeof(a));
    }
    return 0;
}
