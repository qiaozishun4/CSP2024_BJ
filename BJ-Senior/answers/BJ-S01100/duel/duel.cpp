#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;

int a[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = n;
    int lasti = 0, lastv = 0, nowv = a[1], nowi = 1, lastc = 0, nowc = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] > nowv)
        {
            lasti = nowi;
            lastv = nowv;
            nowi = i;
            nowv = a[i];
            lastc += nowc;
            nowc = 0;
        }
        nowc++;
        if(lastc > 0)
        {
            lastc--;
            cnt--;
        }
    }
    cout << cnt << endl;
    return 0;
}