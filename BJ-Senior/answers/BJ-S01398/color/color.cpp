#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int t, n, a[N], res;
bool b[N];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.ans", "w", stdout);
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        res = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int d = (1 << n);
        for(int i = 0; i < d; i++)
        {
            int odres = res;
            res = 0;
            for(int j = 0; j < n; j++)
                b[j] = (i >> j) % 2;
            int x = -1, y = -1;
            for(int j = 0; j < n; j++)
            {
                if(b[j])
                {
                    if(a[j] == a[x] && x != -1) res += a[j];
                    x = j;
                }
                else
                {
                    if(a[j] == a[y] && y != -1) res += a[j];
                    y = j;
                }
            }
            res = max(odres, res);
        }
        cout << res << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
