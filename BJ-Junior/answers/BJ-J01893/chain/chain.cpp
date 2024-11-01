#include <bits/stdc++.h>
using namespace std;
int t;
int main ()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while (t--)
    {
        int n,k,q,l[100001],ns,r[100001],c[100001];
        bool h[200001];
        vector <int> s[100001];
        cin >> n >> k >> q;
        for (int i=1;i<=n;i++)
        {
            cin >> l[i];
            for (int j=1;j<=l[i];j++)
            {
                cin >> ns;
                h[ns]=true;
                s[i].push_back(ns);
            }
        }
        for (int i=1;i<=q;i++)
        {
            cin >> r[i] >> c[i];
            if (!h[c[i]])
            {
                cout << 0 << endl;
                continue;
            }
            cout << 1 << endl;
        }
    }
    return 0;
}
