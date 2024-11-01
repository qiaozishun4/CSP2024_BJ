#include<bits/stdc++.h>
using namespace std;
int n, a[100010], vis[100010], cnt = 0, x = 1;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 2; i <= n; i++){
        for(int j = x; j < i; j++){
            if(vis[j] == 0 && a[i] > a[j]){
                x = j+1;
                vis[j] = 1;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
