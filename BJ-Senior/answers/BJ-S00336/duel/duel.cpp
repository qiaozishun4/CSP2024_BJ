#include<iostream>
#include<cstdio>
using namespace std;

int n, m, cnt[100005], ans, maxx, att[100005];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a;
        cin >> a;
        cnt[a] ++;
        att[a] ++;
        maxx = max(maxx, a);
    }

    ans = n;

    int fst = 1, scnd = 1;
    while(cnt[fst] == 0 && fst <= maxx)
        fst ++;
    scnd = fst + 1;
    while(att[scnd] == 0 && scnd <= maxx)
        scnd ++;

    for(; fst <= maxx && scnd <= maxx;)
    {
        int w = min(cnt[fst], att[scnd]);
        ans -= w;
        cnt[fst] -= w;
        att[scnd] -= w;
        while(cnt[fst] == 0 && fst <= maxx)
            fst ++;
        scnd = fst + 1;
        while(att[scnd] == 0 && scnd <= maxx)
            scnd ++;
        if(fst > maxx || scnd > maxx)
            break;
    }

    cout << ans << endl;

    return 0;
}
