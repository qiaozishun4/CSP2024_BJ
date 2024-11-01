#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (auto i=(a); i <= (b); i++)
#define per(i,a,b) for (auto i=(a); i >= (b); i--)
#define endl '\n'

typedef long long  ll;
typedef unsigned long long  ull;
typedef double lf;

#define N int(1e5+10)

struct Car
{
    int d, v, a;
    Car(int d = 0, int v = 0, int a = 0): d(d), v(v), a(a) {}

    void input()
    {
        cin >> d >> v >> a;
    }
}car[N];

int tester[N];
vector<int> pre[N];

int n, m, L, V;

int getLastTesterBefore(ll l)
{
    if (l > tester[m]) return m;
    if (l < tester[1]) return 0;
    int x = upper_bound(tester + 1, tester + 1 + m, l) - tester;
    return x - 1;
}

int getFirstTesterAfter(ll l)
{
    if (l > tester[m]) return 0;
    if (l < tester[1]) return 1;
    int x = lower_bound(tester + 1, tester + 1 + m, l) - tester;
    return x;
}

void addT(int s, int t = m)
{
    pre[s].emplace_back(t);
}

void clear();
void work()
{
    cin >> n >> m >> L >> V;
    rep (i, 1, n) car[i].input();
    rep (i, 1 ,m) cin >> tester[i];
    sort(tester + 1, tester + 1 + m);

    int cnt0 = 0;

    rep (i, 1, n)
    {
        if (car[i].a == 0) 
        {
            if (car[i].v > V)
            {
                int t = getFirstTesterAfter(car[i].d);
                if (t) 
                {
                    cnt0 ++;
                    addT(t);
                }
            }
            else {}
        }
        else if (car[i].a > 0)
        {
            ll d = 0;
            if (car[i].v > V) d = car[i].d;
            else 
            {
                ll v = car[i].v;
                ll l = (ll(V)*ll(V) - v*v) / (car[i].a * 2);
                while (l * (car[i].a * 2) <= (ll(V)*ll(V) - v*v)) l++;
                d = l + car[i].d;
            }
            int t = getFirstTesterAfter(d);
            if (t) 
            {
                cnt0 ++;
                addT(t);
            }
        }
        else
        {
            if (car[i].v > V)
            {
                int t = getFirstTesterAfter(car[i].d);
                ll v = car[i].v;
                ll l = (ll(V)*ll(V) - v*v) / (car[i].a * 2);
                while (l * (car[i].a * 2) > (ll(V)*ll(V) - v*v)) l++;
                int t1 = getLastTesterBefore(l + car[i].d - 1);

                if (t && t1 && t <= t1)  
                {
                    cnt0 ++;
                    addT(t, t1);
                }
            }
            else {}
        }
    }
    
    int cnt1 = 0;

    priority_queue<int, vector<int>, greater<int>> q;
    rep (i, 1, m)
    {
        for (const int&x: pre[i]) q.push(x);
        if (!q.empty() && q.top() == i)
        {
            cnt1 ++;
            while (!q.empty()) q.pop();
        }
    }

    cnt1 = m - cnt1;

    cout << cnt0 << ' ' << cnt1 << endl;

    clear();
}

void clear()
{
    rep (i, 1, n + 5) car[i] = Car(0,0,0);
    rep (i, 1, m + 5) tester[i] = 0;
    rep (i, 1, m + 5) pre[i].clear();
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N_;
    cin >> N_;
    while (N_--) work();
    return 0;
}