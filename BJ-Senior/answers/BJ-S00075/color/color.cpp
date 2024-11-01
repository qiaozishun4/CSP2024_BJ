#include <iostream>
#include <cstdio>
using namespace std;
int a[20],c[20],n,ans;
bool df(int x,int y)
{

    return (c[x] == c[y]) && (a[x] == a[y]);
}
void dfs(int step)
{
    if(step > n)
    {
        int t = 0;
        for(int i = 2;i <= n;i++)
        {
            int l = i - 1;
            while(!(c[i] == c[l]) && l >= 1) l--;
            if(l < 1 || a[i] != a[l]) continue;
            t += a[i];
        }
        ans = max(ans,t);
        return;
    }
    c[step] = 1;
    dfs(step + 1);
    c[step] = 2;
    dfs(step + 1);

}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}
