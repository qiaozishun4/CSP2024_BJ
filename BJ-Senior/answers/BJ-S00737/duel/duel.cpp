#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+3;

int r[N], bkt[N];
int tmp[N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i];
        tmp[i] = r[i];
    }
    sort(tmp+1, tmp+n+1);
    int sz = unique(tmp+1, tmp+n+1) - tmp - 1;
    for(int i = 1; i <= n; i++)
    {
        //cout << lower_bound(tmp+1, tmp+sz+1, r[i]) - tmp << " ";
        bkt[lower_bound(tmp+1, tmp+sz+1, r[i]) - tmp]++;
    }
    int cnt = 0, last = n, alast = n;
    for(int i = 1; i <= sz; i++)
    {
        //last -= bkt[i];
        alast -= bkt[i];
        last = min(last, alast);
        int used = min(bkt[i], last);
        cnt += (bkt[i] - used);
        last -= used;
    }
    cout << cnt << endl;
    return 0;
}
