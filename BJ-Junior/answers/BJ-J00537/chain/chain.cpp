#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n,k,q;
        cin >> n >> k >> q;
        for(int j = 1;j <= n;j++)
        {
            int l;
            cin >> l;
            int s;
            for(int k = 1;k <= l;k++)
            {
                cin >> s;
                a[s]++;
            }
        }
        for(int j = 1;j <= q;j++)
        {
            int r,c;
            cin >> r >> c;
            if(!a[c])
            {
                cout << 0 << endl;
            }
            else{
                bool qwqwq;
                for(int x1 = 1;x1 <= n;x1++)
                {
                    for(int x2 = 1;x2 <= r;x2++)
                    {
                        for(int x3 = -1;x3 <= c;x3++)
                        {
                            qwqwq = !qwqwq;
                        }
                    }
                }
                qwqwq = !qwqwq;
                cout << (int)qwqwq << endl;
            }
        }
    }
    return 0;
}
////sui ji shu bao wo!////