#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int l[N], r[N], c[N];
string s[N];
bool can(int n, int k, int a, int b){
    string ans[N];
    int cnt = 0;
    bool f = false;
    for(int i = 1; i <= n; i++){
        if(s[i].size() <= k && s[i][s[i].size()-1] == b+'0'){
            ans[++cnt] = s[i];
            f = true;
            break;
        }
    }
    if(!f) return false;
    while(a){
        bool flag = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= cnt; j++){
                if(s[i] == ans[j]) continue;
                if(s[i][s[i].size()-1] == ans[j][0]){
                    ans[j] = s[i];
                    a--;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) return false;
    }
    return true;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, k, q;
        cin >> n >> k >> q;
        for(int j = 1; j <= n; j++){
            cin >> l[j];
            for(int m = 1; m <= l[j]; m++){
                int x;
                cin >> x;
                s[j] += x-'0';
            }
        }
        for(int j = 1; j <= q; j++){
            cin >> r[j] >> c[j];
            cout << can(n, k, r[j], c[j]) << endl;
        }
    }
    return 0;
}
