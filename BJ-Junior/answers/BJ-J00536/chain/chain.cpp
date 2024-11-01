#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> s[N];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            int l;
            cin >> l;
            for(int j = 1;j <= l;j++)
            {
                int v;
                cin >> v;
                s[i].push_back(v);
            }
        }
        while(q--)
        {
            int r, c;
            cin >> r >> c;
            bool flag = false;
            for(int i = 1;i <= n;i++)
            {
                for(int v : s[i])
                {
                    if(v == c)
                    {
                        cout << 1 << '\n';
                        flag = true;
                        i = n + 1;
                        break;
                    }
                }
            }
            if(!flag)
                cout << 0 << '\n';
        }
    }
    return 0;
}