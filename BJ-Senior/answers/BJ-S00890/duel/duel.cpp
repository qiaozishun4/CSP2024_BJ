#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 10;
int n, a[maxn];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[ans]) ans++;
    }
    cout << n - ans << endl;
    return 0;
}