#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, r[N], s;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    sort(r + 1, r + n + 1);
    s = n;
//    for(int i = 1; i <= n; i++)
//        cout << r[i] << ' ';
//    cout << endl;
    for(int i = 1, j = 2; j <= n; i++, j++)
    {
        while(r[j] <= r[i] && j <= n) j++;
        if(j > n) break;
//        cout << i << ' ' << j << endl;
        s--;
    }
    cout << s << endl;

    return 0;
}
