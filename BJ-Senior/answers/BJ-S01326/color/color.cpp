#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2*1e5+10;
const int maxa=1e6+10;
long long t,n,a[maxn],cnt[maxa],fl[maxa];
long long ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            cnt[a[i]]++;
        }
        for (int i=1;i<=n;i++) if (fl[a[i]]==0) ans+=a[i]*cnt[a[i]];
        cout<<ans<<endl;
    }
    return 0;
}