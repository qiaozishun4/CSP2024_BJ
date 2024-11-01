#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 200000 + 10;
int t, n, k, q;
vector<pair<int, int>> a[maxn], pos[maxn], query[101];
bool vis[maxn];
int expt[maxn], l[maxn], ans[maxn];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> k >> q;
        int maxs = 0, maxr = 0, x;
        for(int i = 1; i <= n; i++) {
            cin >> l[i];
            for(int j = 0; j < l[i]; j++) {
                cin >> x;
                a[i].push_back({x, 0});
                pos[x].push_back({i, j});
                maxs = max(maxs, x);
            }
        }
        //for(int i = 1; i <= maxs; i++) sort(pos[i].begin(), pos[i].end());
        for(int i = 1; i <= q; i++) {
            int r, c;
            cin >> r >> c;
            query[r].push_back({c, i});
            maxr = max(maxr, r);
        }

        vis[1] = true;
        for(int round = 1; round <= maxr; round++) {
            for(int i = 1; i <= maxs; i++) {
                if(!vis[i]) continue;
                for(auto pr : pos[i]) {
                    int x = pr.first;
                    int y = pr.second;
                    if(x == expt[i]) continue;
                    a[x][y].second = round;
                }
            }

            memset(vis, false, sizeof(vis));
            memset(expt, 0, sizeof(expt));
            for(int i = 1; i <= n; i++) {
                int last = -1;
                for(int j = 0; j < l[i]; j++) {
                    if(j <= last) {
                        vis[a[i][j].first] = true;
                        if(expt[a[i][j].first] == 0) expt[a[i][j].first] = i;
                        else if(expt[a[i][j].first] != i) expt[a[i][j].first] = 0;
                    }
                    if(a[i][j].second == round) last = j + k - 1;
                }
            }

            for(auto pr : query[round]) {
                ans[pr.second] = vis[pr.first];
            }
            /*
            cerr << "round " << round << endl;
            for(int i = 1; i <= maxs; i++) {
                if(vis[i])
                cerr << "vis " << i << ": " << vis[i] << ", except " << expt[i] << endl;
            }
            cerr << "-----------" << endl;
            */
        }

        for(int i = 1; i <= q; i++) cout << ans[i] << endl;

        //clean
        for(int i = 1; i <= n; i++) a[i].clear();
        for(int i = 1; i <= maxs; i++) pos[i].clear();
        for(int i = 1; i <= maxr; i++) query[i].clear();
        memset(vis, false, sizeof(vis));
        memset(expt, 0, sizeof(expt));

    }
    return 0;
}