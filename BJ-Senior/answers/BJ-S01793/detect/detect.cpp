#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T,n,m,l,v;
int d[N],u[N],a[N],p[N];
int maxn;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--)
    {
        maxn = 0;
        int ans = 0;
        cin >> n >> m >> l >> v;
        for(int i = 1;i <= n;i++)
        {
            cin >> d[i] >> u[i] >> a[i];


        }
        for(int i = 1;i <= m;i++)
        {
            cin >> p[i];
            maxn = max(maxn,p[i]);
        }
        for(int i = 1;i <= n;i++)
        {
            if(u[i] > v && d[i] <= maxn)
            {
                ans++;
            }
        }
        if(ans == 0)
        {
            m++;
        }
        cout << ans << ' ' << m - 1 << endl;
    }
    return 0;
}

