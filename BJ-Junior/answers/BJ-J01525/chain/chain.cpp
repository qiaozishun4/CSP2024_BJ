#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N], cc, tt, f, n, c;

vector<int> b[N];

void dfs(int r, int k, int last){
    if(f) return ;
    if(r == 0){
		//cout << last << " " << cc << endl;
        if(last == c) f = 1;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(i == k) continue;
        int tmp = -1e9;
        for(int j = 1; j <= a[i]; j++){
            
            if(j - tmp < cc && j - tmp >= 1) dfs(r - 1, i, b[i][j]);
            if(b[i][j] == last) tmp = j;
        }
    }
}

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int k, q;
        cin >> n >> k >> q;
        cc = k;
        for(int i = 1; i <= n; i++){
			b[i].clear();
            cin >> a[i];
            b[i].push_back(0);
            for(int j = 1; j <= a[i]; j++){
                int x;
                cin >> x;
                b[i].push_back(x);
            }
        }
        while(q--){
            int r;
            cin >> r >> c;
            if(r == 1){
                bool flag = 0;
                for(int i = 1; i <= n; i++){
                    int last = -1e9;
                    for(int j = 1; j <= a[i]; j++){
                        
                        if(j - last < cc && j - last >= 1){
                            if(b[i][j] == c){
                                flag = 1;
                                break;
                            }
                        }if(b[i][j] == 1) last = j;
                    }
                }
                if(flag) cout << 1 << endl;
                else cout << 0 << endl;
            }else {
                tt = c; f = 0;
                dfs(r, 0, 1);
                if(f) cout << 1 << endl;
                else cout << 0 << endl;
            }
        }
    }
}
