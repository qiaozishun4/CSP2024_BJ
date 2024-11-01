#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node
{
    int num;
    int id;
};
int a_[N], a[N], c[N];
char d[25][N];
int x[10];
int main(){
    freopen("arena.in","r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a_[i];
    for (int i = 1; i <= m; i ++) cin >> c[i];
    int k = 0;
    while (pow(2, k) < n) k ++;
    for (int i = 1; i <= k; i ++)
        for (int j = 1; j <= pow(2, k - i); j ++)
            cin >> d[i][j];
    int T;
    cin >> T;
    while (T --)
    {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for (int i = 1; i <= n; i ++) a[i] = a_[i] ^ x[i % 4];
        int ans = 0;
        for (int o = 1; o <= m; o ++)
        {
            k = 0;
            while (pow(2, k) < c[o]) k ++;
            queue<int> q, nxt;
            for (int i = 1; i <= c[o]; i ++)
                q.push(i);
            for (int ti = k; ti >= 1; ti --)
            {
                for (int i = 1; i <= pow(2, ti - 1); i ++)
                {
                    int x = q.front(); q.pop();
                    int y = q.front(); q.pop();
                    if (d[k - ti + 1][i] - '0' == 0)
                    {
                        if (a[x] >= k - ti + 1) nxt.push(x);
                        else nxt.push(y);
                    }
                    else
                    {
                        if (a[y] >= k - ti + 1) nxt.push(y);
                        else nxt.push(x);
                    }
                }
                while (!nxt.empty())
                    q.push(nxt.front()), nxt.pop();
            }
            ans = ans ^ (o * q.front());
            // cout << q.front() << "!";
        }
        cout << ans << "\n";
    }

    return 0;
}