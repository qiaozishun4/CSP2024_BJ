#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t,n;
struct A
{
    int v;
    int c;
}a[maxn];
int C[maxn],ans = 0;
void dfs(int x)
{
    if(x >= n)
    {
        memset(C,0,sizeof(C));
        for(int i = n;i >= 2;i--)
        {
            int j = i - 1;
            while(a[j].c != a[i].c && j > 0) j--;
            if(a[i].c == a[j].c && a[i].v == a[j].v) C[i] = a[i].v;
        }
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            sum += C[i];
        }
        ans = max(ans,sum);
        //cout << ans << " ";
        return;
    }
    for(int i = 0;i < 2;i++)
    {
        a[x+1].c = i;
        dfs(x + 1);
        //a[x+1].c = 0;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i].v;
        }
        ans = 0;
        a[1].c = 0;
        dfs(1);
        a[1].c = 1;
        dfs(1);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
