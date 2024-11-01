#include <bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[100005],top,sum;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        if(!cnt[x])a[++top]=x;
        cnt[x]++;
    }
    sort(a+1,a+top+1);
    sum=cnt[a[1]];
    for(int i=2;i<=top;i++)
    {
        int temp=min(cnt[a[i]],sum);
        sum-=temp;
        sum+=cnt[a[i]];
    }
    cout << sum;
    return 0;
}