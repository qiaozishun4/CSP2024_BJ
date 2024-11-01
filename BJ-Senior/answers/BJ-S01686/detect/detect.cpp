#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const double EPS = 0.00000001;
int T;
int n, m, L, V;
struct car
{
    double d, v, a;
    int fir, ed;
}alls[N];
double p[N];
bool chk[N];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T;t ++)
    {
        cin >> n >> m >> L >> V;
        int cnt = 0;
        for(int i = 1; i <= n; i ++)
        {
            cin >> alls[i].d >> alls[i].v >> alls[i].a;
            alls[i].fir = -1;
        }
        for(int i = 1; i <= m; i ++) chk[i] = false;
        for(int i = 1; i <= m; i ++) cin >> p[i];
        for(int i = 1; i <= n; i ++) 
        {
            if(alls[i].a >= 0)
            {
                double S = 0.0; 
                if(alls[i].a == 0) S = L * 1.0 + 9.0;
                if(alls[i].a > 0) S = alls[i].d * 1.0 + (V * V * 1.0 - alls[i].v * alls[i].v * 1.0) * 1.0 / (2 * alls[i].a * 1.0) * 1.0;
                if(alls[i].v > V) S = alls[i].d * 1.0 - 0.5;
                //when x = S, vs = V
                int l = 1, r = m;
                /*
                while(l < r)
                {
                    int mid = (l + r) >> 1;
                    if(p[mid] * 1.0 <= S) l = mid + 1;
                    else r = mid;
                }
                */
                if(p[m] * 1.0 - S <= EPS) 
                {
                    l = -1 ;//find first check point
                }
                else{
                    chk[l] = true;
                    cnt += 1;
                }
            }
        }
        cout << cnt << ' ';
        int ans = 0;
        for(int i = 1; i <= m; i ++)
            if(chk[i])
                ans += 1;
        if(cnt != 0) cout << m - 1 << endl;
        else cout << m << endl;
    }
    return 0;
}