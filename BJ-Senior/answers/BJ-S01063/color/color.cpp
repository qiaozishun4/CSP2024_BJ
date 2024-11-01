#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define dF(i,b,a) for(int i=b;i>=a;i--)
#define LL long long
int T,n,a[N];
LL ans;
bool vis[N];
void dfs(int x)
{
    if(x > n)
    {
        int pre1 = 0,pre2 = 0;
        LL sum = 0;
        F(i,1,n)
            if(vis[i])
            {
                if(a[i] == a[pre1]) sum += a[i];
                pre1 = i;
            }
            else
            {
                if(a[i] == a[pre2]) sum  += a[i];
                pre2 = i;
            }
        ans = max(ans,sum);
        return;
    }
    vis[x] = 0;
    dfs(x+1);
    vis[x] = 1;
    dfs(x+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans = 0;
        F(i,1,n) cin>>a[i];
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}