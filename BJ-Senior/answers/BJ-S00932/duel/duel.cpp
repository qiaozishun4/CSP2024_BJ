#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int r[N];

queue <int> q;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int i, j, k;
	int n;
	cin >> n;
	for(i=1; i<=n; i++)
    {
        cin >> r[i];
    }
    sort(r + 1, r + 1 + n);
    while(!q.empty())
    {
        q.pop();
    }
    q.push(r[1]);
    int ans = 0;
    for(i=2; i<=n; i++)
    {
        q.push(r[i]);
        if(r[i] > q.front())
        {
            ans++;
            q.pop();
        }
    }
    cout << n - ans << "\n";
	return 0;
}
