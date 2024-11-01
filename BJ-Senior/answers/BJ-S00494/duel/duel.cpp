#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,d;
};
node a[100005];
bool cmp(node a,node b)
{
    if(a.a!=b.a)
    {
        return a.a<b.a;
    }
    return a.d<b.d;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int i;
    bool flag=1;
    int x=0,y=0;
    for(i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        a[i].a=a[i].d=t;
        if(t!=1&&t!=2)
        {
            flag=0;
        }
        else
        {
            if(t==1)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
    }
    if(flag)
    {
        cout<<x+max(x-y,y-x);
        return 0;
    }
    int cnt=0;
    bool f=0;
    while(cnt<n)
    {
        cnt=0;
        f=0;
        sort(a+1,a+n+1,cmp);
        int mn1,mn2,mn=1000000;
        for(i=2;i<=n;i++)
        {
            if(a[i].a!=-1&&a[i-1].d!=-1&&a[i].a>a[i-1].d)
            {
                if(a[i].a-a[i-1].d<mn)
                {
                    mn1=i-1;
                    mn2=i;
                    mn=a[i].a-a[i-1].d;
                }
                f=1;
            }
        }
        if(!f)
        {
            break;
        }
        a[mn2].a=a[mn1].a=a[mn1].d=-1;
        for(i=1;i<=n;i++)
        {
            if(a[i].a==-1)
            {
                cnt++;
            }
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(a[i].d!=-1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
