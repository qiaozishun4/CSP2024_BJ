#include <bits/stdc++.h>
using namespace std;
vector<int> a[10][10];
bool DFS(int now, int r, int c, bool last1=1, int last2=-1){
    if (r==0 && now==c) return 1;
    if (r==0) return 0;
    for (int i=0; i<10; ++i)
    if (!a[now][i].empty() && (last1 || last2!=i) && DFS(i, r-1, c, a[now][i].size()>1, a[now][i][0])) return 1;
    return 0;
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int n, k, q, x;
        cin >> n >> k >> q;
        for (int j=0; j<n; ++j){
            int l;
            cin >> l;
            vector<short> tmp(l);
            for (int k=0; k<l; ++k){
                cin >> tmp[k];
                for (int l=0; l<k; ++l)
                    a[l][k].push_back(j);
            }
        }
        for (int j=0; j<q; ++j){
            int r, c;
            cin >> r >> c;
            cout << DFS(1, r, c) << endl;
        }
    }
    return 0;
}
