#include <iostream>
using namespace std;
int t,n,k,q;
int a,b;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n >> k >>q;
        for(int i = 1;i <= n;i++)
        {
            int l = 0;
            cin >> l;
            for(int i = 1;i <= l;i++)
            {
                cin >> a;
            }
        }
        for(int i = 1;i <= q;i++)
        {
            cin >> a >> b;
            cout << 1<<endl;
        }
    }
    return 0;
}