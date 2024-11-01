#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[100010];
bool vis[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+n+1);
    ans = n;
    for(int i = 1; i <= n; i ++)
    {
        int l = i+1, r = n;
        bool flag = 0;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(a[mid]>a[i]&&vis[mid] == 0)
            {
                r = mid;
                flag = 1;
            }
            else l = mid+1;
        }
        if(a[l]>a[i]&&vis[l] == 0)
        {
            vis[l] = 1;
            ans --;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
