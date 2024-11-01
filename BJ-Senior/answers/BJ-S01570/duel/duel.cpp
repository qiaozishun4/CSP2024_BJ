#include <bits/stdc++.h>
#define int long long
using namespace std;
int data[100005];
int cnt[100005];
int lst[100005];
int sum[100005];
signed main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        cin >> data[i];
        if(data[i]>2) flag = false;
    }
    sort(data+1, data+1+n);
    if(flag){
        int cnt1 = 0;
        int cnt2 = n;
        for(int i = 1;i <= n;i++){
            if(data[i] == 1){
                cnt1++;
                cnt2--;
            }
        }
        cout << cnt2 - cnt1 + cnt2;
        return 0;
    }
    int l = 1;
    for(int i = 1;i <= n;i++){
        cnt[data[i]] ++;
        if(data[i] != lst[l-1]){
            lst[l] = data[i];
            l++;
        }
    }
    l++;
    for(int i = 1;i <= l;i++){
        sum[i] = sum[i-1] + cnt[lst[i]];
    }
    int ans = 0;
    for(int i = 2;i <= l;i++){
        if(cnt[lst[i]] < sum[i-1]){
            ans = sum[i-1] - cnt[lst[i]];
            for(int j = i-1;j <= l;j++) sum[j] -= cnt[lst[i]];
        }
        else{
            ans = cnt[lst[i]] - sum[i-1];
            for(int j = i;j <= l;j++) sum[j] -= sum[i-1];
            for(int j = 0;j <= i-1;j++) sum[j] = 0;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
