#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int ans;
int a[N];
bool flag[N];
void dfs(int x,int step)
{
    //cout<<step<<" ";
    if(step>x)
    {
        int sum=0;
        int l=-1,r=-1;
        for(int i=1;i<=x;i++)
        {
            if(flag[i])
            {
                if(l==-1) sum+=0;
                else
                {
                    if(a[l]==a[i]) sum+=a[i];
                    else sum+=0;
                }
                l=i;
            }
            else
            {
                if(r==-1) sum+=0;
                else
                {
                    if(a[r]==a[i]) sum+=a[i];
                    else sum+=0;
                }
                r=i;
            }
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<=1;i++)
    {
        flag[step]=i;
        dfs(x,step+1);
        flag[step]=false;
    }
    return;
}
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(n,1);
        cout<<ans<<endl;
    }
    return 0;
}
