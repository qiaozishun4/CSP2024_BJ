#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+10;
const int M=1e6+10;
ll t,n,a[N],c[N],ans;
void dfs(int k)
{
    if(k==n)
    {
        ll x=-1,y=-1,s=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]==1)
            {
                if(a[i]==x)
                {
                    s+=x;
                }
                x=a[i];
            }
            if(c[i]==2)
            {
                if(a[i]==y)
                {
                    s+=y;
                }
                y=a[i];
            }
        }
        ans=max(ans,s);
        return;
    }
    c[k]=1;
    dfs(k+1);
    c[k]=2;
    dfs(k+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        ans=0;
        memset(c,0,sizeof(c));
        dfs(0);
        cout<<ans<<"\n";
    }
    return 0;
}
