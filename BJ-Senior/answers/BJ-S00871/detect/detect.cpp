#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
long long n,m,l,V,cnt2;
long long d[MAXN],v[MAXN],a[MAXN],p[MAXN];
bool c[MAXN],c2[MAXN];
int ans = 0;

void dfs(int P,int cnt)
{
    if(P > m)
    {
        int cnt1 = 0;
        for(int i = 1;i <= m;i++)
        {
            if(c[i]) continue;
            //cout << i << " ";
            for(int j = 1;j <= n;j++)
            {
                if(p[i] < d[j]) continue;
                if(V*V < v[j]*v[j]+2*a[j]*(p[i]-d[j]))
                {
                    c2[j] = 1;
                    //cout << j << " ";
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(c2[i]) cnt1++;
            c2[i] = 0;
        }
        //cout << cnt1 << endl;
        if(cnt1 == cnt2) ans = max(ans,cnt);
        return;
    }
    dfs(P+1,cnt);
    c[P] = 1;
    dfs(P+1,cnt+1);
    c[P] = 0;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cnt2 = ans = 0;
        memset(c2,0,sizeof(c2));
        memset(c,0,sizeof(c));
        cin >> n >> m >> l >> V;
        bool f1 = 1,f2 = 1;
        for(int i = 1;i <= n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            //cout << a[i];
            if(a[i] < 0) f1 = 0;
            if(a[i] >= 0) f2 = 0;
        }
        for(int i = 1;i <= m;i++) cin >> p[i];
        sort(p+1,p+m+1);

        if(f1)
        {
            int cnt = 0;
            for(int i = 1;i <= n;i++)
            {
                if(p[m] < d[i]) continue;
                if(V*V < v[i]*v[i]+2*a[i]*(p[m]-d[i]))
                {
                    cnt++;
                }
            }
            cout << cnt << " " << m-(cnt>=1) << endl;
        }
        else
        {
            for(int i = 1;i <= m;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    if(p[i] < d[j]) continue;
                    if(V*V < v[j]*v[j]+2*a[j]*(p[i]-d[j]))
                    {
                        //cout << j << " " << a[j] << endl;
                        c2[j] = 1;
                    }
                }
            }
            for(int i = 1;i <= n;i++)
            {
                if(c2[i])
                {
                    cnt2++;
                    //cout << i << " ";
                }
                c2[i] = 0;
            }
            cout << cnt2 << " ";
            dfs(1,0);
            cout << ans << endl;
        }

    }
    return 0;
}
