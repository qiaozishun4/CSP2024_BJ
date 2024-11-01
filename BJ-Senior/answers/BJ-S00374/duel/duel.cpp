#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel","r",stdin);
    freopen("duel","w",stdout);
    long long n;
    cin >> n;
    long long r[n+5];
    for(int i = 1;i <= n;i++)
    {
        cin >> r[i];
    }
    sort(r+1, r+n+1);
    long long sum = 1;
    for(int i = 2;i <= n;i++)
    {
        if(r[i] == r[1])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}