#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, ans, j=1, a[N+5], box[N+5], x[N+5];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        box[a[i]]++;
    }
    for(int i = 1; i <= N; i++){
        if(box[i] == 0) continue;
        int sum = 0;
        while(j < i && sum + box[j] <= box[i]) sum += box[j], box[j] = 0, j++;
        if(j != i) box[j] -= (box[i] - sum);
    }
    for(int i = 1; i <= N; i++) ans += box[i];
    cout<<ans;
    return 0;
}
