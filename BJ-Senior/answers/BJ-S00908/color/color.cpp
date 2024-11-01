#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 5;
int t, n, a[N];
bool b[N];
LL s;

void dfs(int x)
{
    if(x == n + 1)
    {
        LL c = 0;
        int m0 = 0, m1 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!b[i])
            {
                if(a[i] == a[m0]) c += a[i];
                m0 = i;
            }
            else
            {
                if(a[i] == a[m1]) c += a[i];
                m1 = i;
            }
        }
        if(c > s) s = c;
//        for(int i = 1; i <= n; i++)
//            cout << b[i] << ' ';
//        cout << endl << ' ' << c << endl;

        return;
    }
    dfs(x + 1);
    b[x] = true;
    dfs(x + 1);
    b[x] = false;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        s = 0;
        dfs(1);
        cout << s << endl;
    }

    return 0;
}
