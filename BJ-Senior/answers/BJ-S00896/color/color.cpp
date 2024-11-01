#include<bits/stdc++.h>
using namespace std;
int a[100005],t,n;
long long ans=0;
bool color[100005],vis[100005];
long long calcscore();

void dfs(int w)
{
    if(w==0)
    {
        if(calcscore()>ans)
        {
            /*
            for(int i=0;i<n;i++)
            {
                cout<<color[i]<<" ";
            }
            cout<<endl;
            */
            ans=calcscore();
        }
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                color[i]=0;
                dfs(w-1);
                color[i]=1;
                dfs(w-1);
                vis[i]=0;
            }
        }
    }
}

long long calcscore()
{
    long long sum=0;
    int c;
    for(int i=0;i<n;i++)
    {
        bool tag=0;
        for(int j=0;j<i;j++)
        {
            if(color[i]==color[j]&&a[i]==a[j])
            {
                tag=1;
            }
        }
        if(tag)
        {
            sum+=a[i];
        }
    }
    return sum;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        dfs(n);
        cout<<ans<<endl;
    }
    return 0;
}
