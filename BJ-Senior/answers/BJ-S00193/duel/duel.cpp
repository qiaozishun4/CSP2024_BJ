#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1;
    int r=1;
    int cnt=n;
    while(l<n)
    {
        if(a[l]<a[r])
        {
            l++;
            cnt--;
            if(r==n)
                break;
        }
        if(a[l]==a[n])
            break;
        r=min(r+1,n);
    }
    cout<<cnt;
    return 0;
}
