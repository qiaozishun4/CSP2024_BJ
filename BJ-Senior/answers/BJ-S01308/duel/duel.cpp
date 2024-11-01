#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, ans, vis[100005], dead[100005];
struct node
{
    int v, id;
} r[100005];

bool operator< (node x, node y)
{
    return x.v < y.v;
}

bool operator== (node x, node y)
{
    return x.v == y.v;
}

bool operator> (node x, node y)
{
    return x.v > y.v;
}

signed main() // jin nian ti gao zu zen me zhe me nan, fu le
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i].v;
        r[i].id = i;
    }
    ans = n;
    sort(r + 1, r + n + 1);
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << "{" << r[i].v << ", " << r[i].id << "}\n";
    // }
    vis[r[1].id] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(dead[r[i].id] || vis[r[i].id])
        {
            continue;
        }
        int id = i + 1;
        for(int j = i - 1; j >= 1; j--)
        {
            if(!dead[r[j].id] && r[j].v < r[i].v)
            {
                id = j;
                break;
            }
        }
        if(id == i + 1)
        {
            for(int j = i - 1; j >= 1; j--)
            {
                if(!dead[r[j].id] && r[j].v == r[i].v)
                {
                    id = j;
                    break;
                }
            }
        }
        if(id != n + 1)
        {
            if(r[id].v < r[i].v)
            {
                dead[r[id].id] = 1;
                ans--;
            }
            vis[r[i].id] = 1;
        }
    }
    cout << ans;

    return 0;
}