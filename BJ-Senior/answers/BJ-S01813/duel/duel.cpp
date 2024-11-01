#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int live = 1;
    int able = 2;
    while(able <= n)
    {
        if(a[able] > a[live])
        {
            live ++;
            able ++;
        }
        else able ++;
    }
    cout << n - live + 1 << endl;
}
