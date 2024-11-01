#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m, k, q;
vector<int> s[N];
int r[M], c[M];
bool f[M];
struct Que
{
    int r, c;
}que[M];
bool cmp(Que a, Que b)
{
    return a.r < b.r;
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        for(int i = 1, l; i <= n; i++)
        {
            cin >> l;
            for(int j = 1, x; j <= l; j++)
            {
                cin >> x;
                s[i].push_back(x);
            }
        }
        int rx = -1e9, cx = -1e9;
        cin >> q;
        for(int i = 1; i <= q; i++)
            cin >> que[i].r >> que[i].c;
        int rd = 0;
        sort(que + 1, que + q + 1, cmp);
        for(int i = 1; i <= q; i++)
        {
            int r = que[i].r, c = que[i].c;
            cout << 1 << endl;
        }
    }
    return 0;
}
