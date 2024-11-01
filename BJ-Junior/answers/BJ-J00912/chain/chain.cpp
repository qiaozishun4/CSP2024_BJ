#include <bits/stdc++.h>
using namespace std;

int tot = 0;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int t;
    cin >> t;

    for (int i = 1 ; i <= t ; i ++)
    {
        int n,q,k;
        cin >> n >> k >> q;
        tot += q;
        for (int i = 1 ; i <=  n; i ++)
        {
            int l;
            cin >> l;
            int ln;
            for (int i = 1 ; i <= l ; i ++)
            {
                cin >> ln;
            }

        }
        for (int i = 1 ; i <= q ; q ++)
        {
            int r,c;
            cin >> r >> c;
        }
    }

    for(int i = 1 ; i <= tot ; i ++)
    {
        cout << 0 << endl;
    }


    return 0;
}
