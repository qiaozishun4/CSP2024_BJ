#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5+100;
ll a[maxn];
ll color[maxn];
ll c;

void dfs(ll id, ll n, ll cnt){

    if(id > n){
        if(cnt > c) c = cnt;
        //cout << "a:";
        //for(int i = 1; i <= n; i++) cout << a[i] << " ";
        //cout << "\ncolor:";
        //for(int i = 1; i <= n; i++) cout << color[i] << " ";
        //cout << "\n";
        //cout << "cnt:" << cnt << " c:" << c << "\n\n";
        return;
    }

    color[id] = 1;
    ll t = 0;
    //cout << "id:" << id << " ";
    for(ll i = id-1; i >= 1; i--){
        if(color[i] == 1){
            if(a[i] == a[id]){
                cnt += a[id];
                t = a[id];
                //cout << "a[i]:" << i << " ";
            }
            break;
        }
    }
    //cout << "ts_cnt:" << cnt << "\n";
    dfs(id + 1, n, cnt);
    cnt -= t;
 //-------------------------------------------------
    t = 0;
    color[id] = 2;
    //cout << "id:" << id << " ";
    for(ll i = id-1; i >= 1; i--){
        if(color[i] == 2){
            if(a[id] == a[i]){
                cnt += a[i];
                t = a[i];
                //cout << "i:" << i << " ";
            }
            break;
        }
    }
    //cout << "ts_cnt:" << cnt << "\n";
    dfs(id+1, n, cnt);
    cnt -= t;
    color[id] = 0;

}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll T; cin >> T;
    while(T--){
        ll n; cin >> n;
        c = 0;
        memset(color, 0, sizeof(color));
        memset(a, 0, sizeof(a));
        for(ll i = 1; i <= n; i++) cin >> a[i];
        dfs(1, n, 0);
        cout << c << "\n";
    }
    return 0;
}
