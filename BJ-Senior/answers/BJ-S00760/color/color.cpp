#include <bits/stdc++.h>
using namespace std;
struct node{
    int num,c;
    bool color;
}a[200005];
int ans,n;
bool write_now_color;
int add_together()
{
    int sum=0;
    for (int i = 1; i <= n; i++)
        sum += a[i].c;
    return sum;
}
bool find_num(int idx)
{
    for (int i = idx-1; i >= 1; i--)
        if (a[i].num == a[idx].num)
            return true;
    return false;
}
bool find_color(int idx)
{
    for (int i = idx-1; i >= 1; i--)
        if (a[i].color == a[idx].color)
            return true;
    return false;
}
void dfs(int idx,bool flag)
{
    if (idx == n+1)
    {
        ans = max(ans,add_together());
        return;
    }
    if (idx>1 && find_num(idx) && find_color(idx))
        a[idx].c = a[idx].num;
    write_now_color = a[idx].color;
    a[idx].color = flag;
    dfs(idx+1,flag);
    a[idx].c = 0;
    a[idx].color = write_now_color;
    write_now_color = a[idx].color;
    a[idx].color = flag;
    dfs(idx+1,!flag);
    a[idx].c = 0;
    a[idx].color = write_now_color;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i].num;
            a[i].color = 0;
            a[i].c = 0;
        }
        ans = 0;
        dfs(1,0);
        cout << ans << "\n";
    }
    return 0;
}