#include<iostream>
#include<map>
using namespace std;
map<int,int> f;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x, f[x]++;
    int ans = 0;
    for(auto [x, y]: f) ans = max(ans, y);
    cout << ans << endl;
    return 0;
}