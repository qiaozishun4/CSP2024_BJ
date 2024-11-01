#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct Node{
    int data, nextlen, hostcnt, hostind;
    vector<int> next;
}node[200005];

int T, n, k, q, l, r, c, tmps[200005];
bool ok;

void dfs(int now, int nowt) {
    if (nowt > r || ok)
        return;

    if (now == c && nowt == r) {
        ok = true;
        return;
    }
    for (int i = 0;i < node[now].nextlen;i++) {
        if (node[node[now].next[i]].hostcnt != 1 || node[now].hostcnt != 1 || node[now].hostind != node[node[now].next[i]].hostind)
            dfs(node[now].next[i], nowt + 1);
    }
}

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n >> k >> q;

        for (int i = 1;i <= n;i++) {
            cin >> l;
            for (int j = 1;j <= l;j++) {
                cin >> tmps[j];
                if (node[tmps[j]].hostcnt == 0) {
                    node[tmps[j]].hostcnt++;
                    node[tmps[j]].hostind = i;
                }
                else {
                    if (i != node[tmps[j]].hostind) {
                        node[tmps[j]].hostcnt++;
                        node[tmps[j]].hostind = i;
                    }

                }
            }


            for (int i = 1;i <= l;i++) {
                for (int j = i + 1;j <= i + k - 1 && j <= l;j++) {
                    node[tmps[i]].next.push_back(tmps[j]);
                    node[tmps[i]].nextlen++;
                }
            }

        }


        for (int i = 1;i <= q;i++) {
            cin >> r >> c;

            ok = false;
            dfs(1, 0);
            if (ok)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
}
