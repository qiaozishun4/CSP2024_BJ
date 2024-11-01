#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0,temp=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            ans+=temp;
            temp=0;
        }
        if(ans) ans--;
        temp++;
    }
    ans+=temp;
    cout<<ans;
    return 0;
}
