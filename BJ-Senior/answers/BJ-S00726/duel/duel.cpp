#include <cstdio>
#include <iostream>
using namespace std;
int n,r[100005],a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> r[i];
        a[r[i]]++;
    }
    int now = 0;
    for (int i = 1;i <= 100000;i++)
    {
        now = max(now,a[i]);
    }
    cout << now << endl;
    return 0;
}