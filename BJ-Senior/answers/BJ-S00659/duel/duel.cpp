#include<bits/stdc++.h>
using namespace std;
int n, a[100005];
signed main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    sort(a + 1, a + n + 1);
    int sum = 0, ans = 0;
    a[0] = -1, a[n + 1] = -1;
    for(int i = 1;i <= n + 1;i++){
        if(a[i] == a[i - 1])
                sum++;
        else
            ans = max(ans, sum), sum = 1;
    }
    cout<<ans;
    return 0;
}
