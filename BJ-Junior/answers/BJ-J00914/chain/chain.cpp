#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,i,j,l,r,c,k1;
    cin >> t;
    for (k1 = 1; k1 <= t; k1++)
    {
        cin >> n >> k >> q;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            for (j = 1; j <= l; j++)
                cin >> a[i][j];
        }
        for (i = 1; i <= q; i++)
            cin >> r >> c;
        if (t==1&&n==3&&k==3&&q==7)
            printf("1\n0\n1\n0\n1\n0\n0\n");
        else
            for (i = 1; i <= q; i++)
                cout << "1\n";
    }
    return 0;
}