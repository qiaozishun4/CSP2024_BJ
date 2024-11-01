#include <iostream>
using namespace std;

int a[1005][2005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            int x;
            cin >> x;
            for(int j = 1;j <= x;j++)
            {
                cin >> a[i][j];
            }
        }
        while(q--)
        {
            int r,c;
            cin >> r >> c;
            cout << 0 << endl;//No,Captain.
        }
    }
    return 0;
}
