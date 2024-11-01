#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
queue <int> q;
int a[N];
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
    q.push(a[1]);
    for(int i = 2;i <= n;i++)
    {
        if(!q.empty() && a[i] > q.front())
            cnt--, q.pop();
        q.push(a[i]);
    }
    cout << cnt << endl;
    return 0;
}