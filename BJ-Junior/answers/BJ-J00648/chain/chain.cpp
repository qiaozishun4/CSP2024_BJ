#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, k, q, l[N];
vector<int> S[N];
namespace Sol1{
    inline void Solve(int r, int c){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < l[i]; j++){
                if(S[i][j] == 1){
                    for(int bgg = j + 1; bgg <= j + k - 1 && bgg < l[i]; bgg++){
                        if(S[i][bgg] == c){
                            cout << 1 << endl;
                            return;
                        }
                    }
                }
            }
        }
        cout << 0 << endl;
        return;
    }
}
namespace Sol2{
    struct Node{
        int what;
        int fa;
        int step;
    };
    inline void Solve(int r, int c){
        queue<Node> q;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < l[i]; j++){
                if(S[i][j] == 1){
                    for(int bgg = j + 1; bgg <= j + k - 1 && bgg < l[i]; bgg++){
                        Node nnnnn;
                        nnnnn.what = S[i][bgg];
                        nnnnn.fa = i;
                        nnnnn.step = 1;
                        q.push(nnnnn);
                    }
                }
            }
        }
        while(!q.empty()){
            Node zyc = q.front();
            q.pop();
            if(zyc.step == r){
                if(zyc.what == c){
                    cout << 1 << endl;
                    return;
                }
            }
            if(zyc.step < r){
                for(int i = 1; i <= n; i++){
                    if(zyc.fa != i){
                        for(int j = 0; j < l[i]; j++){
                            if(S[i][j] == zyc.what){
                                for(int bgg = j + 1; bgg <= j + k - 1 && bgg < l[i]; bgg++){
                                    Node nnnnn;
                                    nnnnn.what = S[i][bgg];
                                    nnnnn.fa = i;
                                    nnnnn.step = zyc.step + 1;
                                    q.push(nnnnn);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << 0 << endl;
        return;
    }
}
inline void Solve(){
    int r, c;
    cin >> r >> c;
    if(r == 1){
        Sol1::Solve(r, c);
        return;
    }
    if(n <= 10 && r <= 5){
        Sol2::Solve(r, c);
        return;
    }
    Sol2::Solve(r, c);
    return;
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++){
            cin >> l[i];
            S[i].clear();
            for(int j = 1, x; j <= l[i]; j++){
                cin >> x;
                S[i].push_back(x);
            }
        }
        while(q--){
            Solve();
        }
    }
    return 0;
}
