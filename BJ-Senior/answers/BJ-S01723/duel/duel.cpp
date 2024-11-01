#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int cnt = 0, cnt2 = 0;
    int now = q.top();
    while(!q.empty() && q.top() == now)
    {
        cnt++;
        q.pop();
    }
    while(!q.empty())
    {
        // cout << cnt << ' ' << q.top() << ',';
        int sec = q.top();
        while(!q.empty() && q.top() == sec)
        {
            cnt2++;
            q.pop();
        }
        // cout << cnt2 << ' ' << q.top() << endl;
        n -= min(cnt, cnt2);
        cnt = max(cnt, cnt2);
        cnt2 = 0;
    }
    cout << cnt << endl;
    return 0;
}
