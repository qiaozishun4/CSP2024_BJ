#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N] , cnt[N];

int main()
{
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int maxn = -1e9;
    for (int i = 0;i <= N;i++) 
        maxn = max(maxn , cnt[i]);
    cout << maxn << endl;
    return 0;
}