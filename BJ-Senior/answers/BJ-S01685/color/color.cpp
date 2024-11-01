#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=2e5;
int T,n,a[N+5],num[N+5],cnt;
ll ans;
void dfs(ll i)
{
    cnt++;
    if(i>n)
    {
        int last0=0,last1=0;
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            cnt++;
            if(num[i]==1)
            {
                if(a[i]==a[last1]) res+=a[i];
                last1=i;
            }
            else
            {
                if(a[i]==a[last0]) res+=a[i];
                last0=i;
            }
        }
        ans=max(ans,res);
        return ;
    }
    if(cnt>6e6) return ;
    for(int x=0;x<=1;x++)
    {
        num[i]=x;
        dfs(i+1);
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt=0,ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
