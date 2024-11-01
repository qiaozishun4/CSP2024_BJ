#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int T,n,k,q,l[N],s[N][N];
bool check(int r,int c)
{
    if(r == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= l[i]; j++)
            {
                 if(s[i][j] == c && j <= k) return 1;
            }
        }
        return 0;
    }
    return 0;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for(int j = 1; j <= l[i]; j++)
            {
                cin >> s[i][j];
            }
        }
        for(int i = 1; i <= q; i++)
        {
            int r,c;
            cin >> r >> c;
            if(check(r,c)) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }
    return 0;
}
