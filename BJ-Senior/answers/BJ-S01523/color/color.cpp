#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],head[1000010]={0},flag[1000010]={0},ans=-1,v[200];
void dfs(int step)
{
    if(step==n+1)
    {
        int dt=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>head[i];j--)
            {
                if(v[j]==v[i])
                {
                    dt++;
                }
            }
            if(dt==0&&v[i]==v[head[i]]&&head[i]>0)
            {
                sum+=a[i];
            }
            dt=0;
        }
        ans=max(ans,sum);
    }
    else
    {
        v[step]=0;
        dfs(step+1);
        v[step]=1;
        dfs(step+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=100)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                head[i]=flag[a[i]];
                flag[a[i]]=i;
            }
            dfs(1);
            cout<<ans<<endl;
            ans=-1;
            memset(v,0,sizeof(v));
            memset(a,0,sizeof(a));
            memset(head,0,sizeof(head));
            memset(flag,0,sizeof(flag));
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            head[i]=flag[a[i]];
            flag[a[i]]=i;
        }
        int red=0,blue=0,redcl=n,bluecl=n+1,val=0;
        if(head[n]>0)
        {
            red+=a[n];
        }
        for(int i=n-1;i>=1;i--)
        {
            if(red>=blue&&(head[redcl]==i||head[bluecl]==i))
            {
                if(head[bluecl]==i)
                {
                    val+=a[i];
                    blue-=a[i];
                    bluecl=i;
                }
                else if(head[redcl]==i)
                {
                    val+=a[i];
                    red-=a[i];
                    redcl=i;
                }
            }
            else if(red<blue&&(head[redcl]==i||head[bluecl]==i))
            {
                if(head[redcl]==i)
                {
                    val+=a[i];
                    red-=a[i];
                    redcl=i;
                }
                else if(head[bluecl]==i)
                {
                    val+=a[i];
                    blue-=a[i];
                    bluecl=i;
                }
            }
            else
            {
                if(red>=blue)
                {
                    if(head[i]>0)
                    {
                        blue+=a[i];
                    }
                    if(head[bluecl]==i)
                    {
                        val+=a[i];
                        blue-=a[i];
                    }
                    bluecl=i;
                }
                else if(red<blue)
                {
                    if(head[i]>0)
                    {
                        red+=a[i];
                    }
                    if(head[redcl]==i)
                    {
                        val+=a[i];
                        red-=a[i];
                    }
                    redcl=i;
                }
            }
        }
        cout<<val<<endl;
        memset(a,0,sizeof(a));
        memset(head,0,sizeof(head));
        memset(flag,0,sizeof(flag));
    }
    return 0;
}
