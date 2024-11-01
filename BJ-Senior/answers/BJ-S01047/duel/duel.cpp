#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

map <int, int> mp;

struct node
{
    int data;
    int sum;
};

bool cmp(node x, node y)
{
    return x.data < y.data;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n, ans = 0, maxx = -1;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int t = 1;
    node hs[N];

    for(map <int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        hs[t].data = iter->first;
        hs[t].sum = iter->second;
        t++;
    }

    sort(hs + 1, hs + mp.size() + 1, cmp);

    for(int i = 1; i < mp.size(); i++)
        ans = max(hs[i].sum, hs[i + 1].sum);

    cout << ans;

    return 0;
}