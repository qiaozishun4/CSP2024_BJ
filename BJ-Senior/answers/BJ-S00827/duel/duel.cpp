#include<bits/stdc++.h>
using namespace std;
int cnt[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int frt = 0;
    for(int i = 1; i <= 100000; i++)
    {
        if(frt > cnt[i]) frt -= cnt[i];
        else frt = 0;
        frt += cnt[i];
    }
    cout << frt;
    return 0;
}
