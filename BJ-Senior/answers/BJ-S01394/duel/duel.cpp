#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int N = 100005;
int n, cnt[N], last, mr;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int r;
        cin >> r;
        cnt[r]++;
        mr = max(r, mr);
    }
    for (int i = 0; i <= mr; i++)
    {
        if (last < cnt[i]) last = cnt[i];
    }
    cout << last << endl;
    return 0;
}
