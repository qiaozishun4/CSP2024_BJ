#include <cstdio>
#include <iostream>
using namespace std;
int T,n,k,q,l,r,c;
int b[200003],cnt[200003];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        for(int j = 1; j <= n; j++)
        {
            cin >> l;
            for(int i = 1; i <= l ;i++)
            {
                int tmp;
                cin >> tmp ;
                b[tmp]++;
            }
        }
        for(int i = 1; i <= q; i++)
        {
            cin >> r >> c;
            if(!b[i]){
                cout << 0 << endl;
                continue;
            }
            else cout << 1 << endl;
        }

    }
    return 0;
}
