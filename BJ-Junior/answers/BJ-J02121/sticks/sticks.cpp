#include<bits/stdc++.h>
using namespace std;
int t,a[15]={6,2,5,5,4,5,6,3,7,6},ans[100005],sum=0x3f3f3f3f;
void dfs(int l,int s)
{
    if(s==0)
    {
        int as=0;
        for(int i=1;i<l;i++)
        {
            as=as*10+i;
        }
        sum=min(sum,as);
        return;
    }
    else if(s==1)
    {
        return;
    }
    for(int i=9;i>=0;i--)
    {
        if(s>=a[i])
        {
            ans[l]=i;
            dfs(l+1,s-a[i]);
            ans[l]=0;
        }
    }
    return;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","r",stdout);
    cin>>t;
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        sum=0x3f3f3f3f;
        int n;
        cin>>n;
        for(int i=9;i>=1;i--)
        {
            if(n>=a[i])
            {
                ans[1]=i;
                dfs(2,n-a[i]);
                ans[1]=0;
            }
        }
        if(sum==0x3f3f3f3f)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<sum<<endl;
    }
    return 0;
}
