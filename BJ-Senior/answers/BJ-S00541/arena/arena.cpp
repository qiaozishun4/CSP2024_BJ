#include<bits/stdc++.h>
using namespace std;
int n, m, ap[100001], c[100001], a[100001], X[5];
string d[40];
vector<int> vec[40];
inline bool is2(int xx){
    for(int i = 0; i < 32; i++) if((1<<i) == xx) return true;
    return false;
}
inline int who_win(int x, int y, int lun, int ju){
    if(x > y) swap(x, y);
    if(d[lun][ju-1] == '0'){
        if(a[x] >= lun) return x;
        else return y;
    }else{
        if(a[y] >= lun) return y;
        else return x;
    }
    return -1;
}
inline int who_win_2(int x, int y, int lun, int ju, bool knowx, bool knowy){
    if(x > y) swap(x, y);
    if(d[lun][ju-1] == '0'){
        if(knowx){
            if(a[x] >= lun) return x;
            else return y;
        }else{
            return x+y;
        }
    }else{
        if(knowy){
            if(a[y] >= lun) return y;
            else return x;
        }else{
            return x+y;
        }
    }
    return -1;
}
inline int get_ans(int poos){
    if(is2(poos)){
        for(int i = 0; i < 35; i++) vec[i].clear();
        int lun = 1;
        for(int i = 1; i <= poos; i++) vec[lun].push_back(i);
        while(vec[lun].size() > 1){
            for(int i = 0; i < vec[lun].size(); i += 2){
                vec[lun+1].push_back(who_win(vec[lun][i], vec[lun][i+1], lun, i/2+1));
            }
            lun++;
        }
        return vec[lun][0];
    }
    int www;
    for(int i = 0; i < 32; i++){
        if((1<<i) >= poos){
            www = i;
            break;
        }
    }
    for(int i = 0; i < 35; i++) vec[i].clear();
    int lun = 1;
    for(int i = 1; i <= (1<<www); i++) vec[lun].push_back(i);
    while(vec[lun].size() > 1){
        for(int i = 0; i < vec[lun].size(); i += 2){
            vec[lun+1].push_back(who_win_2(vec[lun][i], vec[lun][i+1], lun, i/2+1, vec[lun][i]<=poos, vec[lun][i+1]<=poos));
        }
        lun++;
    }
    return vec[lun][0];
}
inline void Solve(){
    for(int i = 0; i < 4; i++) cin >> X[i];
    for(int i = 1; i <= n; i++) a[i] = ap[i] ^ X[i%4];
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans ^= (i*get_ans(c[i]));
    }
    cout << ans << endl;
    return;
}
int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> ap[i];
    for(int i = 1; i <= m; i++) cin >> c[i];
    int K;
    for(int i = 0; i < 32; i++){
        if((1<<i) >= n){
            K = i;
            break;
        }
    }
    for(int i = 1; i <= K; i++){
        cin >> d[i];
    }
    int T;
    cin >> T;
    while(T--){
        Solve();
    }
    return 0;
}