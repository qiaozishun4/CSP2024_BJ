#include <bits/stdc++.h>
using namespace std;
int n,sum;
long long r[1000005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    r[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
    }
    sort(1,n,r);
    for(int i=1;i<=n;i++)
    {
        if (r[i]<r[i+1])
        {
            r[i]=0;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (r[i]!=0)
        {
            sum++;
        }
    }
    cout <<sum;
    return 0;
}
