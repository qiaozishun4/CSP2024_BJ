#include <bits/stdc++.h>
using namespace std;
int a[100005];

bool check(int n)
{
    bool flag = 1;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
        if(a[i] > 0)
            cnt++;
    if(n - cnt == n - 1)
        flag = 0;
    return flag;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
        {
            if(a[i] > a[j] && a[j] != -2 && a[j] != -1 && a[i] != -1)
                a[i] = -2,a[j] = -1;
            if(a[i] < a[j] && a[i] != -2 && a[i] != -1 && a[j] != -1)
                a[i] = -1,a[j] = -2;
            //cout << a[i] << ' ' << a[j] << '\n';
        }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
        if(a[i] != -1)
            cnt++;
    cout << cnt;
    return 0;
}
//10
//136 136 136 2417 136 136 2417 136 136 136
