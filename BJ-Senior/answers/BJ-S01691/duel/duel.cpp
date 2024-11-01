#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct node
{
    int num;
    bool b;
}a[100005];
bool cmp(node x, node y)
{
    return x.num < y.num;
}
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i].num;
        a[i].b = true;
    }
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(a[j].num > a[i].num && a[j].b == true)
            {
                a[i].num = 0;
                a[j].b = false;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i].num != 0)
        {
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}