#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node{
    int st, en;
    int number;
    bool c;
}A[N];
int T, n, m, L, V;
int d, f, a;
int idx, s, ans;

int g[N];
vector<int> h[3010];

void init(){
    for (int i = 1; i <= idx; i++){
        A[i].number = 0, A[i].c = true;
        int l = 1, r = N;
        while(g[l] < A[l].st) l++;
        while(g[r] > A[r].en) r--;

        for(int j = l; j <= r; j++){h[j].push_back(i);}
        A[i].number = r - l + 1;
        if (A[i].number <= 0) A[i].c = false;
    }
}
void dfs(int u, int x){
    if (u + m - x <= ans) return;
    if (x == m){
        ans = min(u, ans);
        return;
    }

    dfs(u, x + 1);
    for(auto y : h[x]){
        A[y].number --;
        if(A[y].number == 0) return;
    }
    dfs(u + 1, x + 1);
    for(auto y : h[x]){
        A[y].number ++;
    }
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> T;
    while (T--){
        idx = 0;
        scanf("%d%d%d%d", &n, &m, &L, &V);

        for (int i = 0; i < n; i++){
            scanf("%d%d%d", &d, &f, &a);
            if (a == 0){
                if (f > V){
                    ++idx;
                    A[idx].st = d, A[idx].en = L;
                }
            }
            else if (a > 0){
                s = (V * V - f * f) / (a * 2) + d;
                if (s <= L){
                    ++idx;
                    A[idx].st = max(d, s), A[idx].en = L;
                }
            }
            else{
                if(f > V){
                    s = (V * V - f * f + a * 2 - 1) / (a * 2) + d;
                    ++idx;
                    A[idx].st = d, A[idx].en = min(L, s);
                }
            }
        }

        ans = 0;
        for(int i = 1; i <= m ; i++){
            scanf("%d", &g[i]);
        }

        sort(g + 1, g + m + 1);
        init();
        dfs(0, 1);
        cout << ans <<'\n';
    }

    return 0;
}
