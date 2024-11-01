#include<bits/stdc++.h>
using namespace std;
int t , n , k , q , l[200005] , r[200005] , c[200005] , maxr;
vector<int> s[200005] , mp[200005];
__int128 dis[200005];
bool equal1[200005];
inline void add(int u , int v)
{
    mp[u].push_back(v);
    return;
}
inline void dfs(int p , int deep)
{
    if(deep > 10)
    {
        return;
    }
    dis[p] |= deep;
    for(int i = 0 ; i < mp[p].size() ; i++)
    {
        dfs(mp[p][i] , deep + 1);
    }
    return;
}
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> l[i];
            s[i].push_back(0);
            for(int j = 1 ; j <= l[i] ; j++)
            {
                s[i].push_back(0);
                cin >> s[i][j];
            }
        }
        maxr = -1;
        for(int i = 1 ; i <= q ; i++)
        {
            cin >> r[i] >> c[i];
            maxr = max(maxr , r[i]);
        }
        if(maxr == 1)
        {
            memset(equal1 , 0 , sizeof(equal1));
            for(int j = 1 ; j <= l[1] ; j++)
            {
                for(int ad = 1 ; ad < k ; ad++)
                {
                    if(j + ad > l[1])
                    {
                            break;
                    }
                    equal1[s[1][j + ad]] = 1;
                }
            }
            for(int i = 1 ; i <= q ; i++)
            {
                if(equal1[c[i]])
                {
                    cout << "1\n";
                }
                else
                {
                    cout << "0\n";
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                s[i].clear();
            }
            for(int i = 1 ; i <= 200000 ; i++)
            {
                mp[i].clear();
            }
            continue;
        }
        memset(dis , 0 , sizeof(dis));
        for(int i = 1 ; i <= n  ; i++)
        {
            for(int j = 1 ; j <= l[i] ; j++)
            {
                if(l[i] - j <= 20 || k <= 20)
                {
                    for(int ad = 1 ; ad < k ; ad++)
                    {
                        if(j + ad > l[i])
                        {
                            break;
                        }
                        add(s[i][j] , s[i][j + ad]);
                    }
                }
                else
                {
                    for(int ad = 1 ; ad <= 20 ; ad++)
                    {
                        if(j + ad > l[i])
                        {
                            break;
                        }
                        add(s[i][j] , s[i][j + rand() % min(k , l[i] - j + 1) + 1]);
                    }
                }
            }
        }
        dfs(1 , 0);
        for(int i = 1 ; i <= q ; i++)
        {
            if((dis[c[i]] >> r[i]) & 1)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            s[i].clear();
        }
        for(int i = 1 ; i <= 200000 ; i++)
        {
            mp[i].clear();
        }
    }
    return 0;
}