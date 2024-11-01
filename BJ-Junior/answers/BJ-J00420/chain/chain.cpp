#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int T, n, K, q, l[100005], r, c;
vector<int> s[100005];
bool flag;

void dfs(int step, int x, int lst)
{
    if(step > r)
    {

        if(x == c) flag = true;
        return;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(i == lst) continue;
        for(int j = 0; j < l[i]; j ++)
            if(s[i][j] == x)
                for(int k = j + 1; k < min(l[i], j + K); k ++)
                    dfs(step + 1, s[i][k], i);
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while(T --)
    {
        cin >> n >> K >> q;
        for(int i = 1; i <= n; i ++)
        {
            cin >> l[i];
            for(int j = 1; j <= l[i]; j ++)
            {
                int x;
                cin >> x;
                s[i].push_back(x);
            }
        }

        for(int i = 1; i <= q; i ++)
        {
            cin >> r >> c;
            dfs(1, 1, 0);
            cout << flag << endl;
            flag = false;
            for(int j = 1; j <= n; j ++)
                s[j].clear();
        }
    }
    return 0;
}
