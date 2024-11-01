#include<iostream>
#include<algorithm>
using namespace std;

const int MXN=1e5+10;
int a[MXN];

int main()
{
    ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);int pt=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[pt+1]<a[i]) pt++;
        // cout<<i<<' '<<pt<<endl;
    }cout<<n-pt<<endl;
    return 0;
}