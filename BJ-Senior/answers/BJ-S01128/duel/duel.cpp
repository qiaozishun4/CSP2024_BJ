#include <bits/stdc++.h>
using namespace std;
int n,a[100005],cnt,tmp,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        if(a[i] != a[i - 1]){
            cnt += tmp;
            tmp = 0;
        }
        if(cnt){
            ans++;
            cnt--;
        }
        tmp++;
    }
    cout << n - ans;
    return 0;
}
