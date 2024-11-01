#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int r[maxN];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        cin >> r[i];
    }

    sort(r + 1, r + 1 + n);

    deque<int> que;
    que.push_back(r[1]);
    for(int i = 2; i <= n; i++)
    {
        if(r[i] > que.front())
        {
            que.pop_front();
            que.push_back(r[i]);
        }
        else
        {
            que.push_back(r[i]);
        }
    }

    cout << que.size();
    return 0;
}
