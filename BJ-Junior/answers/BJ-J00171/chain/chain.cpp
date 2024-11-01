#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

const int NMAX = 1100;
const int LMAX = 2100;
const int RMAX = 11;

struct Node
{
    int x;
    int s;
    int r;
};

int T;
int N, K, Q;
int st[NMAX], ed[NMAX]; // [)
int cur_int_idx;
map<int, int> i2idx, idx2i;
int cur_S_pos, S[LMAX];
int visit[NMAX][LMAX][RMAX];

void BFS(int t)
{
    deque<Node> Q;
    for(int i = 1;i <= N;i += 1) {
        for(int j = st[i];j < ed[i];j += 1) {
            if(S[j] != 1) {
                continue;
            }
            for(int k = 2;k <= K && j + k - 1 < ed[i];k += 1) {
                if(visit[i][S[j + k - 1]][1] != t) {
                    visit[i][S[j + k - 1]][1] = t;
                    Q.push_back((Node){i, S[j + k - 1], 1});
                }
            }
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop_front();
        int x = cur.x;
        int s = cur.s;
        int r = cur.r;
        // printf("x: %d, s: %d, r: %d\n", x, idx2i[s], r);
        if(r + 1 >= RMAX)
            continue;
        for(int i = 1;i <= N;i += 1) {
            if(i == x)
                continue;
            for(int j = st[i];j < ed[i];j += 1) {
                if(S[j] != s)
                    continue;
                for(int k = 2;k <= K && j + k - 1 < ed[i];k += 1) {
                    if(visit[i][S[j + k - 1]][r + 1] != t) {
                        visit[i][S[j + k - 1]][r + 1] = t;
                        Q.push_back((Node){i, S[j + k - 1], r + 1});
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%d", &T);
    for(int t = 1;t <= T;t += 1) {
        scanf("%d %d %d", &N, &K, &Q);
        cur_S_pos = 0;
        i2idx.clear();
        idx2i.clear();
        cur_int_idx = 1;
        i2idx[1] = cur_int_idx;
        idx2i[cur_int_idx] = 1;
        for(int i = 1;i <= N;i += 1) {
            int l;
            scanf("%d", &l);
            st[i] = cur_S_pos;
            for(int j = 0;j < l;j += 1) {
                int s;
                scanf("%d", &s);
                if(i2idx.find(s) == i2idx.end()) {
                    cur_int_idx += 1;
                    i2idx[s] = cur_int_idx;
                    idx2i[cur_int_idx] = s;
                    s = cur_int_idx;
                } else {
                    s = i2idx[s];
                }
                S[cur_S_pos] = s;
                cur_S_pos += 1;
            }
            ed[i] = cur_S_pos;
        }
        BFS(t);
        for(int q = 1;q <= Q;q += 1) {
            int r, c;
            scanf("%d %d", &r, &c);
            int ans = 0;
            if(i2idx.find(c) != i2idx.end()) {
                c = i2idx[c];
                for(int i = 1;i <= N;i += 1) {
                    if(visit[i][c][r] == t) {
                        ans = 1;
                        break;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    exit(0);
}