#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100010], i, lef = 1, last[100010], st;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    last[1] = a[1];
    st = 1;
    for (i = 2; i <= n; i++)
    {
        if(a[i] == last[st])
            last[++lef] = a[i];
        else
        {
            st++;
            last[++lef] = a[i];
        }
    }
    cout << lef - st + 1;
    return 0;
    // Ah!
}