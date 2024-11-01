#include<bits/stdc++.h>
using namespace std;
int n, m;
int raw_a[100005], c[100005], a0[100005], a[100005];
int coin[20][20];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> raw_a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    int k = (int)(log2(n - 1)) + 1;
    for(int r = 1; r <= k; r++)
    {
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++) coin[r][i + 1] = s[i] - '0';
    }
    // return 0;
    int T;
    cin >> T;
    while(T--)
    {
        int x[4];
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1; i <= n; i++)
        {
            a0[i] = (raw_a[i] ^ x[i % 4]);
        }
        long long ans = 0;
        for(int test = 1; test <= m; test++)
        {
            queue<int> q;
            for(int i = 1; i <= n; i++) q.push(a0[i]);
            int rr = log2(c[test]);
            for(int r = 1; r <= rr; r++)
            {
                for(int i = 1; i <= c[test] >> rr; i++)
                {
                    int a = q.front();
                    q.pop();
                    int b = q.front();
                    q.pop();
                    if(coin[r][i] == 0)
                    {
                        if(a >= r) q.push(a);
                        else q.push(b);
                    }
                    else
                    {
                        if(b >= r) q.push(b);
                        else q.push(a);
                    }
                }
            }
            // cout << q.front() << endl;
            ans ^= (test * a0[q.front()]);
        }
        cout << ans << endl;
    }
    return 0;
}
