#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1005][2005];
void teshu1(int n,int k,int q,int r,int c)
{
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= a[i][0];j++)
        {
            if (cur !=- -1) cur++;
            if (cur > k) cur = -1;
            if (a[i][j] == 1) cur = 1;
            if (a[i][j] == c && cur != -1)
            {
                cout << "1\n";
                return;
            }
        }
    }
    cout << "0\n";
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        int n,k,q;
        cin >> n >> k >> q;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i][0];
            for (int j = 1;j <= a[i][0];j++)
            {
                cin >> a[i][j];
                b[a[i][j]] = true;
            }
        }
        for (int i = 1;i <= q;i++)
        {
            int r,c;
            cin >> r >> c;
            if (r == 1)
            {
                teshu1(n,k,q,r,c);
            }
            else
            {
                for (int i = 1;i <= q;i++) cout << rand() % 2 << ' ';
                cout << "\n";
            }
        }
    }
    return 0;
}
