#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int p = 2, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        while(p <= n && a[p] <= a[i]) p++;
        if(a[p] > a[i]) cnt++, p++;
    }
    cout << n - cnt << endl;
    return 0;
}
