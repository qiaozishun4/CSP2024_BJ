#include <bits/stdc++.h>

using namespace std;
int n, r[100005], cnt = 1;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> r[i];
    sort(r+1, r+n+1);
    for(int i = 2;i <= n;i++){
        if(r[i] > r[cnt]) cnt++;
    }
    cout << n - cnt + 1;
    return 0;
}
