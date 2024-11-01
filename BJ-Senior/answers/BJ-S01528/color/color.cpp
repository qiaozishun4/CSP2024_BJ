#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0;
int fd(int arr[],int now)
{
    int anss=0;
    int b=-1,r=-1;
    for(int i=0;i<now;i++)
    {
        if(arr[i]==1&&b==-1)b=i;
        else if(arr[i]==0&&r==-1)r=i;
        else if(arr[i]==1&&a[i]==a[b])
        {
            anss+=a[i];
            b=i;
        }
        else if(arr[i]==0&&a[i]==a[r])
        {
            anss+=a[i];
            r=i;
        }
    }
    return anss;
}
void dfs(int now,int arr[])
{
    if(now>=n)
    {
        ans=max(fd(arr,now),ans);
        return;
    }
    arr[now]=0;
    dfs(now+1,arr);
    arr[now]=1;
    dfs(now+1,arr);
}
int arr[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        n=0;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        ans=0;
        dfs(0,arr);
        cout<<ans<<endl;
    }
    return 0;
}


