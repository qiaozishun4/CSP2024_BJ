#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+7;
int a[N],f[N],cnt[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int ans=n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    int s=0;
    cnt[a[1]]++;
    for(int i=2; i<=n; i++)
    {
        cnt[a[i]]++;
        if(a[i]>a[i-1]) f[i]=f[i-1]+cnt[a[i-1]];
        else f[i]=f[i-1];
        if(s<f[i]) s++;
    }
    cout<<ans-s<<endl;
    return 0;
}
