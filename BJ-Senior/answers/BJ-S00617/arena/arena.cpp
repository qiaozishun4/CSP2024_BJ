#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m, K;
ll ap[200001], a[200001];
pair <vector <int>, ll> res[20][400001];
bool p[20][400001];
pair <int, int> q[100001];

int nlg(int x)
{
    if (x == 1) return 0;
    return __lg(x - 1) + 1;
}

bool cmp(pair <int, int> f, pair <int, int> b)
{
    return f.second < b.second;
}

void Upd(int r, int g)
{
    if (!r) return;
    int gl = g * 2 - 1, gr = g * 2;
 /*   if (!res[r - 1][gl].second && !res[r - 1][gr].second) // all determined
    {
        if (!p[r][g])
        {
            if (a[res[r - 1][gl].first] >= r) res[r][g].first = res[r - 1][gl].first;
            else res[r][g].first = res[r - 1][gr].first;
        }
        else
        {
            if (a[res[r - 1][gr].first] >= r) res[r][g].first = res[r - 1][gr].first;
            else res[r][g].first = res[r - 1][gl].first;
        }
    }
    else if (!res[r - 1][gl].first && !res[r - 1][gr].first) // all nondetermined
    {
        res[r][g].second = res[r - 1][gl].second + res[r - 1][gr].second;
    }
    else // left determined / partially determined
    {
        if (!p[r][g])
        {
            
        }
        else
        {

        }
    }*/
    if (!p[r][g])
    {
        if (!res[r - 1][gl].second) 
        {
            assert(res[r - 1][gl].first.size() == 1);
            if (a[res[r - 1][gl].first[0]] >= r) res[r][g] = res[r - 1][gl];
            else res[r][g] = res[r - 1][gr];
        }
        else if (!res[r - 1][gl].first.size()) 
        {
            res[r][g].first = res[r - 1][gr].first;
            res[r][g].second = res[r - 1][gl].second + res[r - 1][gr].second;
        }
        else
        {
            vector <int> tmp;
            assert(res[r - 1][gl].second);
            for (auto it : res[r - 1][gl].first) 
            {
                if (a[it] >= r) tmp.push_back(it);
            }
            res[r][g].first = tmp;
            for (auto it : res[r - 1][gr].first) res[r][g].first.push_back(it);
            res[r][g].second = res[r - 1][gl].second + res[r - 1][gr].second;
        }
    }
    else
    {
        if (!res[r - 1][gr].second)
        {
            assert(res[r - 1][gr].first.size() == 1);
            if (a[res[r - 1][gr].first[0]] >= r) res[r][g] = res[r - 1][gr];
            else res[r][g] = res[r - 1][gl];
        }
        else if (!res[r - 1][gr].first.size())
        {
            res[r][g].first = res[r - 1][gl].first;
            res[r][g].second = res[r - 1][gl].second + res[r - 1][gr].second;
        }
        else
        {
            vector <int> tmp;
            assert(res[r - 1][gr].second);
            for (auto it : res[r - 1][gr].first)
            {
                if (a[it] >= r) tmp.push_back(it);
            }
            res[r][g].first = tmp;
            for (auto it : res[r - 1][gl].first) res[r][g].first.push_back(it);
            res[r][g].second = res[r - 1][gl].second + res[r - 1][gr].second;
        }
    }
}

ll ans[100001];
ll _x[4];
void Solve()
{
    for (int i = 0; i < 4; i++) cin >> _x[i];
    for (int i = 1; i <= n; i++) a[i] = ap[i] ^ _x[i % 4];
    for (int i = 1; i <= (1 << K); i++) // (1 << K) may > n
    {
        vector <int> tmp;
        res[0][i] = {tmp, i};
    }
    for (int i = 1; i <= K; i++) 
    {
        for (int j = 1; j <= (1 << (K - i)); j++) Upd(i, j);
    }
    for (int i = 1; i <= m; i++)
    {
        int rd = nlg(q[i].second); // ans for this : res[rd][1]
        for (int j = q[i - 1].second + 1; j <= q[i].second; j++) 
        {
            vector <int> tmp;
            tmp.push_back(j);
            res[0][j] = {tmp, 0};
            int cur = j;
            for (int k = 1; k <= K; k++)
            {
                cur = (cur + 1) / 2;
                Upd(k, cur);
            }
        }
        ans[q[i].first] = 0;
        for (auto it : res[rd][1].first) ans[q[i].first] += (ll)it;
        ans[q[i].first] += res[rd][1].second;
    }
    ll fans = 0;
    for (int i = 1; i <= m; i++) fans ^= ans[i] * i;
    cout << fans << endl;
    return;
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> ap[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].second;
        q[i].first = i;
    }
    sort(q + 1, q + m + 1, cmp);
    K = nlg(n);
    for (int i = 1; i <= K; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= (1 << (K - i)); j++) p[i][j] = (s[j - 1] == '1' ? true : false);
    }
    int _;
    cin >> _;
    while (_--) Solve();
    return 0;
}