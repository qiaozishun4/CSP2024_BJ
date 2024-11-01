#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
queue<int> q;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = n;
    for(int i = 1;i <= n;i++)
    {
        if(q.empty() || q.front() >= a[i])
            q.push(a[i]);
        else
        {
            q.pop();
            q.push(a[i]);
            cnt--;
        }
    }
    cout << cnt << '\n';
    return 0;
}