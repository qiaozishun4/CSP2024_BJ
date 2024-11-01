#include<bits/stdc++.h>
using namespace std;
int t , n , a[200005] , ans;
bool col[200005];
inline void check()
{
    int cnt = 0 , lb = 0 , lr = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(col[i])
        {
            if(a[lr] == a[i])
            {
                cnt += a[i];
            }
            lr = i;
        }
        else
        {
            if(a[lb] == a[i])
            {
                cnt += a[i];
            }
            lb = i;
        }
    }
    ans = max(cnt , ans);
    return;
}
inline void dfs(int p)
{
    if(p > n)
    {
        check();
        return;
    }
    col[p] = 0;
    dfs(p + 1);
    col[p] = 1;
    dfs(p + 1);
    return;
}
int main()
{
    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
        }
        ans = 0;
        if(n <= 20)
        {
            dfs(1);
            cout << ans << '\n';
        }
        else
        {
            cout << "0\n";
        }
    }
    return 0;
}