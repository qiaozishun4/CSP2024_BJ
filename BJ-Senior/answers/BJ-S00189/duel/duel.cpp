// 第一题 大概率100分
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
int a[MAXN];
bool ans[MAXN];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int mid = (n+1)/2;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 2)
            flag = false;
    }
    if (flag)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
                cnt ++;
        }
        if (cnt < mid)
            cout << n-cnt;
        if (cnt > mid)
            cout << cnt;
        if (cnt == mid)
        {
            if (n % 2 == 0)
                cout << n-cnt;
            else
                cout << cnt;
        }
        return 0;
    }
    memset(ans, true, sizeof(ans));
    sort(a+1, a+n+1);
    if (n % 2 == 0 && a[mid] != a[mid+1])
        cout << mid << endl;
    else if (n % 2 == 1 && a[mid-1] != a[mid] && a[mid] != a[mid+1])
        cout << mid << endl;
    else
    {
        int x = a[mid];
        int cnt = 0;
        for (int i = 1; i  <= n; i++)
        {
            if (a[i] == x)
                cnt ++;
        }
        cout << cnt;
    }
    return 0;
}
