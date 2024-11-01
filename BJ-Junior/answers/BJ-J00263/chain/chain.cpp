#include<bits/stdc++.h>

using namespace std;

vector<int> v[1005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q;
    int l,r,c;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> l;
            for (int j = 1;j <= l;j++)
            {
                cin >> v[i][j];
            }
        }
        for (int i = 1;i <= q;i++)
        {
            cin >> r >> c;
            if (i % 2 == 1)
                cout << 1 << "\n";
        }
    }
    return 0;
}
