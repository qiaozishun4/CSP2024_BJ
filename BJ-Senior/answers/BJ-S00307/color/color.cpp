#include<bits/stdc++.h>
using namespace std;
int c[1000];
long long n,a[1000],ans=0;
void dfs(int step,long long sum,int r,int b)
{
    if (step>n)
    {
        ans=max(ans,sum);
        return;
    }
    for (int i=0;i<=1;i++)
    {
        if (i==0)dfs(step+1,sum+(r==a[step])*r,a[step],b);
        if (i==1)dfs(step+1,sum+(b==a[step])*b,r,a[step]);
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long t;
    cin >> t;
    for (int i=1;i<=t;i++)
    {
        cin >> n;
        for (int j=1;j<=n;j++)
        {
            cin >> a[j];
        }
        ans=0;
        dfs(1,0,0,0);
        cout << ans << endl;
    }
    return 0;
}
