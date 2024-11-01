#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005],cnt[1000005],cnt1[1000005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        cnt1[a[i]]++;

    }
    sort(a + 1,a + n + 1);
    for(int l = 1,r = 2;r <= n;)
    {
        while(!cnt[a[l]]) l++;
        while((a[l] >= a[r] || !cnt1[a[r]] ) && r <= n) r++;
        if(r <= n && cnt1[a[r]])
        {
            cnt[a[l]]--;
            cnt1[a[r]]--;
            r++;
        }
    }
    int ans = 0;
    for(int i = 1;i <= 1000000;i++)
    {
        ans += cnt[i];

    }
    cout << ans;
    return 0;
}
