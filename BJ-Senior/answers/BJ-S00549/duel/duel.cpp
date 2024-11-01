#include <bits/stdc++.h>
using namespace std;
int n, ans;
int r[100020], used[100020], live[100020];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> r[i];
    sort(r + 1, r + n + 1);
    ans = n;
    for(int i = 1; i <= n; i++)
    {
        if(live[i]) continue;
        for(int j = i + 1; j <= n; j++)
        {
            if(live[j]) continue;
            if(r[i] < r[j] && !live[i] && !live[j] && !used[j])
            {
                live[i] = 1, used[j] = 1;
                ans--;
                break;
            }
        }
    }
    for(int i = n; i >= 1; i--)
    {
        if(!live[i] && used[i])
        {
            for(int j = 1; j < i; j++)
            {
                if(r[i] < r[j] && !live[i])
                {
                    live[i] = 1;
                    used[j] = 1;
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}