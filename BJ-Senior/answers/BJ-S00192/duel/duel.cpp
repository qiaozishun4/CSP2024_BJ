#include<bits/stdc++.h>

using namespace std;

const int NR = 1e5 + 5;
int r[NR], d[NR];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    sort(r + 1, r + n + 1);
    int pos1 = 1, pos2 = 0;
    for(int i = 1; i <= n; i++)
        if(r[i] > r[pos1])
        {
            pos2 = i;
            break;
        }
    for(int i = 1; i <= n; i++)
        d[i] = 1;
    int ans = n, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pos2 > n) break;
        if(d[pos2] == 1) cnt++;
        d[pos2++] = 0;
        if(d[pos1] == 1) cnt++;
        d[pos1++] = -1;
        ans--;
        while(r[pos2] == r[pos1]) pos2++;
        if(cnt == n) break;
    }
    cout << ans << endl;
    return 0;
}
