#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int i=2,j=1;
    while(i<=n)
    {
        while(a[i]<=a[j])
        {
            i++;
        }
        ans--;
        i++;j++;
    }
    cout<<ans;
    return 0;
}
