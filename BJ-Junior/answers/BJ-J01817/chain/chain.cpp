#include <bits/stdc++.h>
using namespace std;

int T,n,k,q,l[1010],s[1010][2010],r,c;
bool f[200010],f1;

void dfs(int m,int y,int p){
    cout << m << " " << y << " " << p << endl;
    if(y == r){
        if(m == c){
            f1 = true;
        }
        return;
    }
    if(f1){
        return;
    }
    for(int i = 1;i <= n;i++){
        if(i == p){
            return;
        }
        for(int j = 1;j <= l[i];j++){
            if(s[i][j] == m){
                for(int u = 1;u < k;u++){
                    dfs(s[i][j + u],y + 1,i);
                }
            }
            if(f1){
                return;
            }
        }
    }
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin >> T;

    while(T--){
        memset(f,0,sizeof(f));
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            cin >> l[i];
            for(int j = 1;j <= l[i];j++){
                cin >> s[i][j];
                f[s[i][j]] = true;
            }
        }
        while(q--){
            cin >> r >> c;
            if(!f[c]){
                cout << 0 << endl;
                continue;
            }
            f1 = false;
            dfs(1,0,0);
            if(f1){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
