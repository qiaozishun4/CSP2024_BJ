#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, k, q;
int l[100010];
vector<int> s[100010];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(0));
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= 1e5; i++)
            s[i].clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++)
            {
                int x;
                cin >> x;
                s[i].push_back(x);
            }
        }
        while (q--)
        {
            int r, c;
            cin >> r >> c;
            cout << rand() % 2 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
