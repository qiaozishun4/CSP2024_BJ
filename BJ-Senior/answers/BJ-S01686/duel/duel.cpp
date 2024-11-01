#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int r[N], t[N];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    int k = 9999999;
    for(int i = 1; i <= n; i ++) 
    {
        cin >> r[i];
        k = min(k, r[i]);
        t[r[i]] ++ ;
    }
    int ans = 0;
    for(int i = 1; i < N; i ++)
    {
        if(t[i])
        {
            ans = max(0, ans - t[i]);
            ans += t[i];
        }
    }
    cout << ans << endl;
    return 0;
}