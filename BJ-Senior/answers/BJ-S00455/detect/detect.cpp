#include <iostream>
#include <cmath>
using namespace std;
#define int long long
//freopen
// freopen

int calcspeed_sq(int v0_sq, int a, int s)
{
    return v0_sq + 2 * a * s;
}
long double calc_s(int v0_sq, int v_sq, int a)
{
    return (long double)(v_sq - v0_sq) / 2. / a;
}

struct Car
{
    int d, v, a, v_sq;
} car[100010];

int p[100010]; // speed checker
int pos_l[1000010];

int n, m, l, V, V_sq;

void solve()
{
    cin >> n >> m >> l >> V;
    V_sq = V * V;
    for(int i = 1; i <= n; i++)
    {
        cin >> car[i].d >> car[i].v >> car[i].a;
        car[i].v_sq = car[i].v * car[i].v;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> p[i];
        for(int j = p[i - 1] + 1; j <= p[i]; j++)
            pos_l[j] = i;
    }
    for(int j = p[m] + 1; j <= l; j++)
        pos_l[j] = -1;

    int ans1 = 0;
    for(int i = 1; i <= n; i++) // for every car
    {
        if(car[i].d > p[m])
            continue;
        if(car[i].a == 0)
            if(car[i].v > V)
                ans1++;
        if(car[i].a > 0)
        {
            int cari_v_sq = calcspeed_sq(car[i].v_sq, car[i].a, p[m] - car[i].d);
            if(cari_v_sq > V_sq)
                ans1++;
        }
        if(car[i].a < 0)
        {
            int j = pos_l[car[i].d];
            int cari_v_sq = calcspeed_sq(car[i].v_sq, car[i].a, p[j] - car[i].d);
            if(cari_v_sq > V_sq)
                ans1++;
        }
    }
    cout << ans1 << ' ';
    if(ans1 == 0)
        cout << m << endl;
    else
        cout << m - 1 << endl;
    return;
}
signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--)
        solve();
    return 0;
}
