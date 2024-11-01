#include <iostream>
#include <cstring>
using namespace std;

int a[200005];
int col[200005];
int n,ans = 0;

int check()
{
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i - 1;j >= 1;j--)
        {
            if(col[j] == col[i])
            {
                if(a[i] == a[j])
                {
                    cnt += a[i];
                    //cout << i << " " << j << " " << a[i] << " " << a[j] << endl;
                }
            }
        }
    }
    return cnt;
}

void dfs(int x)
{
    ans = max(ans,check());
    for(int i = x + 1;i <= n;i++)
    {
        col[i] = 1;
        dfs(i);
        col[i] = 0;
    }
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(col,0,sizeof(col));
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        dfs(0);
        cout << ans << endl;
    }

    return 0;
}
