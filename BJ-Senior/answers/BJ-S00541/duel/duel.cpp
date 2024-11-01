#include<bits/stdc++.h>
using namespace std;
int n, a[100005], aliver[100005], attacker[100005];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int cnt = 1, tot = 0;
    for(int i = 2; i <= n + 1; i++){
        if(a[i] != a[i-1]){
            aliver[++tot] = cnt;
            cnt = 0;
        }
        cnt++;
    }
    for(int i = 1; i <= tot; i++) attacker[i] = aliver[i];
    for(int i = 1; i < tot; i++){
        for(int j = i + 1; j <= tot; j++){
            if(aliver[i] >= attacker[j]){
                aliver[i] -= attacker[j];
                attacker[j] = 0;
            }else{
                attacker[j] -= aliver[i];
                aliver[i] = 0;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= tot; i++){
        ans += aliver[i];
    }
    cout << ans << endl;
    return 0;
}