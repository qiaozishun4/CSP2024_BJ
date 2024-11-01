#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    ans = n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int cnt = 0,cnt2 = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] != a[i - 1]){
            cnt += cnt2;
            cnt2 = 0;
        }
        if(cnt){
            cnt--;
            ans--;
        }
        cnt2++;
    }
    cout << ans;
    return 0;
}
