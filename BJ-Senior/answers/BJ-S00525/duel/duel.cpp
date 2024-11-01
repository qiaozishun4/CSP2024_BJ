#include <bits/stdc++.h>
using namespace std;
long long n,a[10005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    int sum = n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)
            continue;
        for(int j = 1;j <= n;j++)
        {
            if(a[i] > a[j] && a[j] != 0)
            {
                a[j] = 0;
                sum -= 1;
                break;
            }
            if(a[j] == a[i])
                break;
        }
    }
    cout << sum;
}
