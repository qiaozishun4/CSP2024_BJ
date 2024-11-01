#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector <int> s[100005];
bool f[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n;i++)
        {
            s[i].clear();
            int l;
            cin >> l;
            bool flag = 0;
            int id;
            while (l--)
            {
                if (id > 0) id--;
                int x;
                cin >> x;
                if (flag && id > 0) f[x] = 1;
                s[i].push_back(x);
                if (x == 1)
                {
                    flag = 1;
                    id = k;
                }
            }
        }
        while (q--)
        {
            int r,c;
            cin >> r >> c;
            if (n == 1 && r != 1) cout << 0 << endl;
            else cout << f[c] << endl;
        }
    }
    return 0;
}
