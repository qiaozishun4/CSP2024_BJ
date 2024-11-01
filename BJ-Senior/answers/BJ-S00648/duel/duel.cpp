#include <bits/stdc++.h>
using namespace std;
int n, r[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    int ans=n;
    for(int i = 1;i<=n;i++)
        cin >> r[i];
    sort(r+1,r+n+1);
    for(int i = 2;i<=n;i++)
    {
        for(int j = i-1;j>=1;j--)
        {
            if(r[i]>r[j])
            {
                r[j]=1e9;
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
