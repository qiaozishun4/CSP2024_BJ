#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100005],cnt[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(cnt[i] != 0 && cnt[j] != 0){
                ans += (cnt[i] <= cnt[j] ? cnt[i] : cnt[j]);
            }
        }
    }
    cout << n - ans;
    return 0;
}
