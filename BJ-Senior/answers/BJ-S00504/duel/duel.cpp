#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int n;
int a[100005];


int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
//    for(int i = 1; i <= n; ++i)
//        cout << a[i] << " ";

    int cnt = 1, remain = 1, ans = n;
    for(int i = 2; i <= n; ++i)
    {
        if(a[i] != a[i - 1])
        {
            ans -= min(remain, cnt);
            remain += cnt - min(remain, cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    ans -= min(remain, cnt);
    remain += cnt - min(remain, cnt);
    cnt = 1;

    cout << ans + 1 << endl;


    return 0;
}
