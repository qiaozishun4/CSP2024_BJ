#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int t,n,a[N],ans;
bool color[N];

void dfs(int step)
{
    if(step == n + 1)
    {
        int sum = 0;
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1;j--)
                if(color[i] == color[j])
                {
                    if(a[i] == a[j]) sum += a[i];
                    break;
                }
        ans = max(ans,sum);
        return ;
    }

    color[step] = 0;
    dfs(step+1);
    color[step] = 1;
    dfs(step+1);
    return ;
}

signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--)
    {
        ans = 0;
        memset(color,0,sizeof(color));
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        if(n <= 20) dfs(1);
        else ans = 0;
        cout << ans << endl;
    }
    return 0;
}
