#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 100000; i++)
    {
        if(a[i])
        {
            if(cnt > 0)
            {
                if(a[i] >= cnt) cnt = 0;
                else cnt -= a[i];
            }
            cnt += a[i];
        }
    }
    cout << cnt;
    return 0;
}
