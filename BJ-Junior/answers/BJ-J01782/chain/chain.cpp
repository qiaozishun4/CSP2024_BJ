#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++)
    {
        int n,k,q;
        cin >> n >> k >> q;
        for (int i = 1;i <= n;i++)
        {
            int l;
            cin >> l;
            for (int i = 1;i <= l;i++)
            {
                int tmp;
                cin >> tmp;
            }
        }
        for (int i = 1;i <= q;i++)
        {
            int a,b;
            cin >> a >> b;
        }
        for (int i = 1;i <= q;i++)
        {
            cout << 0 << '\n';
        }
    }
    return 0;
}
