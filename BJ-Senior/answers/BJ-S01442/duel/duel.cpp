#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;++i)
        scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    int cnt = n, j = 1;
    for(int i = 1;i <= n;++i)
    {
        if(i != j && a[j] < a[i])
        {
            cnt--;
            j++;
        }
    }
    cout << cnt;
    return 0;
}
