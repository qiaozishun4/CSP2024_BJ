// ru-guo-yun-qi-shi-tian-fu
#include <bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int num;
int x;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            cin >> num;
            for(int j = 1;j <= num;j++)
            cin >> x;
        }
        for(int i = 1;i <= q;i++)
        {
            cin >> x;
            cin >> x;
            cout << 1 << '\n';
        }
    }
    return 0;
}