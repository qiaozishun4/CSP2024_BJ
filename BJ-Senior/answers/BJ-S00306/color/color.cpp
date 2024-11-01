#include<bits/stdc++.h>
using namespace std;
int n;
bool col[200005];
int a[200005];
int maxn=0;
void dfs(int step)
{
    if(step>n)
    {
        int last0=-2e9,last1=-2e9,sum=0;
        for(int i = 1; i<=n; i++)
        {
            if(col[i]==1)
            {
                if(last1==a[i]) sum+=a[i];
                last1=a[i];
            }
            else{
                if(last0==a[i]) sum+=a[i];
                last0=a[i];
            }
        }
        maxn=max(maxn,sum);
        return;
    }
    col[step]=0;
    dfs(step+1);
    col[step]=1;
    dfs(step+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        maxn=0;
        cin>>n;
        for(int i = 1; i<=n; i++)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}