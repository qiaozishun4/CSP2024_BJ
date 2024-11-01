#include<bits/stdc++.h>
using namespace std;
int a[100010], r[100010], b[100010];
bool chk(int cur){
    int cnt = 0;
    for(int i = 1; i <= cur; i++){
        if(b[i] > 0) cnt++;
    }
    if(cnt != 1 && cnt != 0) return true;
    return false;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    int cur = 0;
    for(int i = 1; i <= n; i++){
        if(r[i] != r[i - 1]) ++cur;
        a[cur]++;
        b[cur] = a[cur];
    }
    int cur1 = 1;
    while(chk(cur)){
        for(int i = 1; i <= cur; i++){
            if(a[i] == 0) continue;
            if(b[i + 1] == 0) cur1++;
            if(a[i] >= b[i + cur1]){
                a[i] -= a[i + cur1];
                b[i] = (b[i] - a[i + cur1] >= 0 ? b[i] - a[i + cur1] : 0);
                b[i + cur1] = 0;
            }
            else{
                a[i] = 0;
                b[i] = 0;
                b[i + cur1] -= a[i];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= cur; i++){
        ans += a[i];
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}