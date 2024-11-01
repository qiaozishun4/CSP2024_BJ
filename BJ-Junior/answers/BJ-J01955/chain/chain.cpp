#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int M = 1e3 + 10;
const int K = 2e3 + 10;

int T, n, k, Q;
int l[N], s[M][K];

struct node
{
    int r, c, p;
};

void insert()
{
    cin >> n >> k >> Q;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i];
        for(int j = 1; j <= l[i]; j++)
            cin >> s[i][j];
    }
}

void work()
{
    insert();  
    while(Q--)
    {
        int r, cc;
        cin >> r >> cc;
        // cout << r << " " << cc << endl;
        queue <node> q;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= l[i]; j++)
                if(s[i][j] == 1)
                    for(int kk = j + 1; kk <= n && kk <= j + k - 1; kk++)
                        q.push({1, s[i][kk], i});
        // cout << "PUSH OK\n";
        bool flag = 0;
        // cout << r << " " << cc << endl;
        while(!q.empty())
        {
            int a = q.front().r, b = q.front().c, c = q.front().p;
            q.pop();
            // cout << a << " " << b << " " << c << endl;
        // cout << r << " " << cc << endl;
            if(a == r)
            {
                if(b == cc)
                    cout << 1 << '\n', flag = 1;//, cout << r << " " << cc << " " << a << " " << b << '\n';
            }
            if(flag)
                break;
            if(a > r)
                break;
            // cout << k << endl;
            for(int i = 1; i <= n; i++)
                if(i != c)
                    for(int j = 1; j <= l[i]; j++)
                        if(s[i][j] == b)
                            for(int kk = j + 1; kk <= n && kk <= j + k - 1; kk++)
                                q.push({a + 1, s[i][kk], i});//, cout << i << " " << s[i][kk] << endl;
        }
        if(!flag)
            cout << 0 << '\n';// << '\n';
    }  
}

signed main()
{
    freopen("chain.out", "w", stdout);
    freopen("chain.in", "r", stdin);
    cin >> T;
    while(T--)
        work();
}