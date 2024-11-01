#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 1];
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = i + 1; j <= n; j ++)
        {
            if(a[i] < a[j] && ! used[j])
            {
                a[i] = -1;
                used[j] = 1;
                break;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
        if(a[i] != -1)
            cnt ++;
    cout << cnt;
    return 0;
}