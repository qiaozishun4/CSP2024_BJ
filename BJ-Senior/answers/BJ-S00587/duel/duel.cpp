#include <bits/stdc++.h>
using namespace std;
bool v[100005], s[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int R[100005];
    for(int i=1; i<=n; i++)
    {
        cin >> R[i];
    }
    sort(R+1, R+n+1);

    for(int i=1; i<=n-1; i++)
        for(int j=i; j<=n; j++)
            if(!v[j] && !s[j] && R[j] > R[i])
            {
                v[i] = 1;
                s[j] = 1;
                break;
            }
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(!v[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}