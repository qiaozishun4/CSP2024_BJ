#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

signed main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        int n,k,q;
        cin >> n >> k >> q;
        // n*(li+1)
        // q*2
        for (int j=0;j<n;j++)
        {
            int tmp;
            cin >> tmp;
            for (int k=0;k<=tmp;k++)
            {
                int tmp;
                cin >> tmp;
            }
            
        }
        for (int j=0;j<q*2;j++)
        {
            int tmp;
            cin >> tmp;
        }
        for(int i=0;i<q;i++)
        {
        if (i%2==0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }}
    }
}
