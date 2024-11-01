#include <bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
bool ond[100005],done[100005],all;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1;i <= n / 2;i++)
    {
        ond[i * 2 - 1] = cmp(i * 2,i * 2 - 1);
        done[i * 2 - 1] = 1;
    }
    all = 1;
    for (int i = 1;i <= n - 1;i++)
    {
        if (!ond[i])
        {
            ans++;
            if (!done[i])
            {
                all = 0;
            }
        }
    }
    if (!(!all && n % 2 == 1))
    {
        ans++;
    }
    cout << ans;
    return 0;
}
