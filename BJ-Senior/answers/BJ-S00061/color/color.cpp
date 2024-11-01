#include <bits/stdc++.h>
using namespace std;
const long long N=200005;
long long a[N],b[N];
long long ans;
long long sh,sl,sum,n;
long long i;
void dfs(long long x)
{
    if(x>n)
    {
        sh=0;
        sl=0;
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                if(a[i]==a[sh])
                {
                    sum=sum+a[i];
                }
                sh=i;
            }
            else
            {
                if(a[i]==a[sl])
                {
                    sum=sum+a[i];
                }
                sl=i;
            }
        }
        ans=max(ans,sum);
        return ;
    }
    b[x]=0;
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
