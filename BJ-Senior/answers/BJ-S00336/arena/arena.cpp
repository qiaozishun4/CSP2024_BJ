#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;

long long n, m, k, t, a[100005], c[100005], b[100005], ans, cnt, num;
bool flag;
string s[10005];

long long number(int ending)
{
    queue<int> q;
    for(int i = 1; i <= ending; i ++)
        q.push(b[i]);
    for(int i = 1; i <= ending / 2; i ++)
    {
        for(int j = 0; j < ending / i; j ++)
        {
            int f = q.front();
            q.pop();
            int s1 = q.front();
            q.pop();
            if(s[i - 1][j * i] == '0')
                if(a[f] < i - 1)
                    q.push(s1);
                else
                    q.push(f);
            else
                if(a[s1] < i - 1)
                    q.push(f);
                else
                    q.push(s1);
        }
    }
    return q.front();
}

void dfs(int step, int ending)
{
    if(step > ending)
    {
        cnt += number(ending);
        return;
    }

    int maxx = log2(ending);
    for(int i = 1; i <= maxx - 1; i ++)
    {
        b[step] = (1 << i) - 1;
        dfs(step + 1, ending);
    }
}

int l(int x)
{
    int k = log2(x);
    if(1 << k == x) return x;
    return 1 << k + 1;
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int j = 1; j <= m; j ++)
        cin >> c[j];
    sort(c + 1, c + m + 1);
    cin >> s[1];
    for(int i = 2; i <= log2(l(s[1].size())) + 1; i ++)
        cin >> s[i];
    cin >> t;
    while(t --)
    {
        int x[4];
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1; i <= n; i ++)
            b[i] = a[i] ^ x[i % 4];
        for(int i = 1; i <= m; i ++)
        {
            int k = log2(c[i]);
            if(1 << k == c[i]) dfs(c[i] + 1, c[i]);
            else dfs(c[i] + 1, 1 << k + 1);
            if(flag == false) num = i * cnt;
            else num ^= (i * cnt);
            cnt = 0;
        }
        cout << ans << endl;

        flag = false;
        ans = 0;
    }
    return 0;
}
