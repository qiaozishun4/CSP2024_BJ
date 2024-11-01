#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int n, k, q, l, a;
vector<int> vec[100005];
bool dfs(int p, int beginn, int sum, int endd)
{
    if(p == sum)
    {
        return beginn == endd;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            if(vec[i][j] == beginn)
            {
                for(int l = 1; l < k; l++)
                {
                    if((p + 1 == sum && vec[i][j + l] != endd) || j + l >= vec[i].size())
                    {
                        continue;
                    }
                    if(dfs(p + 1, vec[i][j + l], sum, endd))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        int r[q + 1], c[q + 1];
        if(n == 1)
        {
            for(int i = 1; i <= q; i++)
            {
                cout << 0 << endl;
            }
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> l;
            for(int j = 1; j <= l; j++)
            {
                cin >> a;
                vec[i].push_back(a);
            }
        }
        for(int i = 1; i <= q; i++)
        {
            cin >> r[i] >> c[i];
            if(r[i] == 1)
            {
                bool flag = false;
                for(int j = 1; j <= n; j++)
                {
                    int pos1 = -1, pos2 = -1;
                    for(int l = 0; l < vec[j].size(); l++)
                    {
                        if(vec[j][l] == 1)
                        {
                            pos1 = l;
                        }
                        if(vec[j][l] == c[i] && pos1 != -1)
                        {
                            pos2 = l;
                            break;
                        }
                    }
                    if(pos2 != -1 && pos2 - pos1 <= k)
                    {
                        flag = true;
                        break;
                    }
                }
                cout << flag << endl;
            }
            else
            {
                cout << dfs(0, 1, r[i], c[i]) << endl;
            }
        }
    }
    return 0;
}

