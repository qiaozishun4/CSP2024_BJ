#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005], x[4];
bool d[105][105];
queue<int> q;
int ans;
int n;
int v;
void f(int r, int g)
{
    if(r == 0)
    {
        ans += q.front();
        return;
    }
    if(g == pow(2, r - 1))
    {
        int dx = q.front();
        q.pop();
        int dy = q.front();
        q.pop();
        if(d[v - r + 1][g] == 0)
        {
            int y = 0;
            if(dx <= n) y = a[dx];
            else
            {
                q.push(dx);
                f(r - 1, 1);
                for(int i = 1; i < n;i++)
                {
                    int u = q.front();
                    q.pop();
                    q.push(u);
                }
                q.pop();
                q.push(dy);
                f(r - 1, 1);
                for(int i = 1; i < n;i++)
                {
                    int u = q.front();
                    q.pop();
                    q.push(u);
                }
                return;
            }
            if(y >= r)
            {
                q.push(dx);
                f(r - 1, 1);
            }
            else
            {
                q.push(dy);
                f(r - 1, 1);
            }
        }
        else
        {
            swap(dx, dy);
            int y = 0;
            if(dx <= n) y = a[dx];
            else
            {
                q.push(dx);
                f(r - 1, 1);
                for(int i = 1; i < n;i++)
                {
                    int u = q.front();
                    q.pop();
                    q.push(u);
                }
                q.pop();
                q.push(dy);
                f(r - 1, 1);
                for(int i = 1; i < n;i++)
                {
                    int u = q.front();
                    q.pop();
                    q.push(u);
                }
                return;
            }
            if(y >= r)
            {
                q.push(dx);
                f(r - 1, 1);
            }
            else
            {
                q.push(dy);
                f(r - 1, 1);
            }
        }
        return;
    }
    int dx = q.front();
    q.pop();
    int dy = q.front();
    q.pop();
    if(d[v - r + 1][g] == 0)
    {
        int y = 0;
        if(dx <= n) y = a[dx];
        else
        {
            q.push(dx);
            f(r, g + 1);
            for(int i = 1; i < n;i++)
            {
                int u = q.front();
                q.pop();
                q.push(u);
            }
            q.pop();
            q.push(dy);
            f(r, g + 1);
            for(int i = 1; i < n;i++)
            {
                int u = q.front();
                q.pop();
                q.push(u);
            }
            return;
        }
        if(y >= r)
        {
            q.push(dx);
            f(r, g + 1);
        }
        else
        {
            q.push(dy);
            f(r, g + 1);
        }
    }
    else
    {
        swap(dx, dy);
        int y = 0;
        if(dx <= n) y = a[dx];
        else
        {
            q.push(dx);
            f(r, g + 1);
            for(int i = 1; i < n;i++)
            {
                int u = q.front();
                q.pop();
                q.push(u);
            }
            q.pop();
            q.push(dy);
            f(r, g + 1);
            for(int i = 1; i < n;i++)
            {
                int u = q.front();
                q.pop();
                q.push(u);
            }
            return;
        }
        if(y >= r)
        {
            q.push(dx);
            f(r, g + 1);
        }
        else
        {
            q.push(dy);
            f(r, g + 1);
        }
    }
    return;
}
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n;i++) cin >> a[i];
    for(int i = 1; i <= m;i++) cin >> c[i];
    int o = n;
    int k = 0;
    while(o != 0)
    {
        o /= 2;
        k++;
    }
    cout << k << endl;
    for(int i = 1; i <= k;i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < pow(2, k - i);j++)
        {
            if(s[j] == '0') d[i][j + 1] = 0;
            else d[i][j + 1] = 1;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int x0, x1, x2, x3;
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1; i <= n;i++) b[i] = a[i] ^ (x[i % 4]);
        int sum = 0;
        for(int i = 1; i <= m;i++)
        {
            ans = 0;
            v = 0;
            int z = c[i];
            while(z != 0)
            {
                z /= 2;
                v++;
            }
            int w = pow(2, v);
            if(w != n) v++;
            for(int j = 1; j <= pow(2, v);j++) q.push(j);
            f(v, 1);
            cout << ans << endl;
            if(i == 1) sum = ans * c[i];
            else sum ^= ans * c[i];
        }
        cout << sum << endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005], c[100005], x[4];
bool d[105][105];
queue<long long> q;
long long ans, n, v;
void f(long long r)
{
    if(r == 0)
    {
        ans += q.front();
        return;
    }
    for(long long i = 1; i <= pow(2, r-);i++)
    {
        long long dx = q.front();
        q.pop();
        long long dy = q.front();
        q.pop();
        if(d[v - r + 1][i] == 0)
        {
            if(a[dx] >= r) q.push(dx);
            else q.push(dy);
        }
        else
        {
            if(a[dy] >= r) q.push(dy);
            else q.push(dx);
        }
    }
    f(r - 1);
    return;
}
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n;i++) cin >> a[i];
    for(int i = 1; i <= m;i++) cin >> c[i];
    long long o = n;
    long long k = 0;
    while(o != 0)
    {
        o /= 2;
        k++;
    }
    for(int i = 1; i <= k;i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < pow(2, k - i);j++)
        {
            if(s[j] == '0') d[i][j + 1] = 0;
            else d[i][j + 1] = 1;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        long long x0, x1, x2, x3;
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1; i <= n;i++) b[i] = a[i] ^ (x[i % 4]);
        long long sum = 0;
        for(int i = 1; i <= m;i++)
        {
            ans = 0;
            v = 0;
            for(long long j = 1; j <= q.size();j++) q.pop();
            int z = c[i];
            while(z != 0)
            {
                z /= 2;
                v++;
            }
            for(long long j = 1; j <= pow(2, v);j++) q.push(j);
            f(v);
            //cout << ans << endl;
            if(i == 1) sum = ans * c[i];
            else sum ^= ans * c[i];
        }
        cout << sum << endl;
    }
    return 0;
}
*/


