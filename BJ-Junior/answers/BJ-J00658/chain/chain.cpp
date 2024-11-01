#include <bits/stdc++.h>
using namespace std;
int t, n, k, q;
int sl[1020];
struct node
{
    int rd, last;
};

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        int now = 1, s[1020][2020];
        for(int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;
            sl[i] = l;
            for(int j = 1; j <= l; j++)
            {
                cin >> s[i][j];
            }
        }
        for(int i = 1; i <= q; i++)
        {
            int r, c;
            bool flag1 = 0, flag2 = 0;
            cin >> r >> c;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= sl[i]; j++)
                {
                    if(s[i][j] == c)
                    {
                        flag1 = 1;
                    }
                    if(s[i][j] == 1)
                    {
                        flag2 = 1;
                    }
                }
                if(flag1 && flag2) break;
            }
            if(!flag1 || !flag2) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}