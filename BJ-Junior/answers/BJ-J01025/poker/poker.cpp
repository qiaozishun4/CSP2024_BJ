#include <cstdio>
#include <iostream>
using namespace std;

int n, ans = 0;
char c1[60], c2[60];
bool cntd[300], cntc[300], cnth[300], cnts[300];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c1[i] >> c2[i];
        if (c1[i] == 'D') cntd[c2[i]] = true;
        if (c1[i] == 'C') cntc[c2[i]] = true;
        if (c1[i] == 'H') cnth[c2[i]] = true;
        if (c1[i] == 'S') cnts[c2[i]] = true;
    }
    for (char i = '2'; i <= '9'; i++)
    {
        if (!cntd[i]) ans++;
        if (!cntc[i]) ans++;
        if (!cnth[i]) ans++;
        if (!cnts[i]) ans++;
    }
    if (!cntd['A']) ans++;
    if (!cntc['A']) ans++;
    if (!cnth['A']) ans++;
    if (!cnts['A']) ans++;
    if (!cntd['T']) ans++;
    if (!cntc['T']) ans++;
    if (!cnth['T']) ans++;
    if (!cnts['T']) ans++;
    if (!cntd['J']) ans++;
    if (!cntc['J']) ans++;
    if (!cnth['J']) ans++;
    if (!cnts['J']) ans++;
    if (!cntd['Q']) ans++;
    if (!cntc['Q']) ans++;
    if (!cnth['Q']) ans++;
    if (!cnts['Q']) ans++;
    if (!cntd['K']) ans++;
    if (!cntc['K']) ans++;
    if (!cnth['K']) ans++;
    if (!cnts['K']) ans++;
    cout << ans << endl;
    return 0;
}
