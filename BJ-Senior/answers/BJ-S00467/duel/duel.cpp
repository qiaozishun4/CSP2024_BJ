#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin >> n;
    long long maxx = 0;
    for(long long i = 1;i <= n;i++)
    {
        long long x;
        cin >> x;
        maxx = max(maxx,x);
        a[x]++;
    }
    long long cnt = 0,last = 0;
    for(long long i = 1;i <= maxx;i++)
    {
        if(a[i])
        {
            if(last == 0) last = a[i];
            else last += a[i] - min(last,a[i]);
        }

    }
    cout << last << endl;
    return 0;
}
