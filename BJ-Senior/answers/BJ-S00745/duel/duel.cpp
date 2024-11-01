#include<bits/stdc++.h>
using namespace std;
const int N=1E5+1;
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int now=0,ans=n;
    for(int i=1;i<=n;i++)
    {
        while(a[i]>=a[now] && now<=n)
            now++;
        if(a[i]>=a[now] || now>n)
            break;
        ans--;
        now++;
    }
    cout<<ans<<endl;
    return 0;
}
