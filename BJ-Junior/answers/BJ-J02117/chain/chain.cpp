#include<bits/stdc++.h>
using namespace std;
struct node
{
    int now, lst, st;
};
int n, len, q, idx;
int a[2005];
map<int, int> uni;
vector<pair<int, int> > g[2005];

bool bfs(int r, int ed)
{
    queue<node> q;
    q.push({1, -1, 0});
    while(!q.empty())
    {
        node p = q.front();
        // cout << p.now << ' ' << p.lst << ' ' << p.st << endl;
        q.pop();
        if(p.now == ed && p.st == r) return 1;
        if(p.st > r) continue;
        for(auto i : g[p.now])
        {
            // cout << i.first << ';';
            if(i.second != p.lst)
            {
                // cout << '!';
                q.push({i.first, i.second, p.st + 1});
            }
            // cout << ' ';
        }
        // cout << endl;
    }
    return false;
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> len >> q;
        idx = 0;
        for(int i = 1; i <= 2000; i++) g[i].clear();
        uni.clear();
        for(int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;
            // cout << l << ':' << endl;
            for(int j = 1; j <= l; j++)
            {
                cin >> a[j];
                if(!uni[a[j]]) uni[a[j]] = ++idx;
                for(int k = max(1, j - len + 1); k < j; k++)
                {
                    // cout << a[k] << ',' << uni[a[k]] << ',' << k << ' ' << a[j] << ',' << uni[a[j]] << ',' << j << endl;
                    g[uni[a[k]]].push_back({uni[a[j]], i});
                }
            }
            // cout << endl;
        }
        // for(int i = 1; i <= 6; i++) cout << g[i].size() << ' ';
        // cout << endl << endl;
        // ans += q;
        while(q--)
        {
            int r, ed;
            cin >> r >> ed;
            if(!uni[ed])
            {
                cout << 0 << endl;
                continue;
            }
            cout << bfs(r, ed) << endl;
            // cout << "-----------------------------" << endl;
        }
    }
    // cout << ans << endl;
    return 0;
}
