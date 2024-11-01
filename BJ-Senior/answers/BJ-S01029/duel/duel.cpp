#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int N=1e6;
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[cnt]&&a[cnt]!=-1){
            a[cnt]=-1;
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=-1) ans++;
    cout<<ans;
    return 0;
}
