#include <bits/stdc++.h>
using namespace std;

const int ma = 1e5+5;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, a[ma];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n + 1);
    int cnt = 0, temp = 1;
    for(int i = 2; i <=n; i++)
    {
        if(a[i]>a[temp])
        {
            a[temp] = 0;
            temp++;
        }
    }
    for(int i = 1; i <= n; i++)
        if(a[i] != 0)
            cnt++;
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
