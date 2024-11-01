#include <bits/stdc++.h>
using namespace std;

#define q double

const int ma = 1e5+5;

bool vce(int d, int v, int a, int V)
{
    if(2.0*a*d+v*v*1.0 > V*V)
        return true;
    else
        return false;
}


int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;cin >> t;
    while(t--)
    {
        int n, m , l, V;cin >> n >> m >> l >> V;
        int d[ma], v[ma], a[ma], ce[ma];

        bool vis[ma];

        for(int i = 1; i<= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for(int i = 1; i <=m ; i++)
            cin >> ce[i];
        bool va = true, vb = true, vc = true;
        for(int i = 1; i <= n; i++)
        {
            if(a[i]!=0)
            {
                va = false;
                continue;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i]<=0)
            {
                vb = false;
                continue;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i]>=0)
            {
                vc = false;
                continue;
            }
        }
        if(va == true)
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                if(vce(ce[m]-d[i],v[i],a[i],V) == true && ce[m] >= d[i])
                    cnt++;
            cout << cnt << " " << m-1 << endl;
        }
        if(vb == true)
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                if(vce(ce[m]-d[i],v[i],a[i],V) == true && ce[m] >= d[i])
                    cnt++;
            cout << cnt << " " << m-1 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
