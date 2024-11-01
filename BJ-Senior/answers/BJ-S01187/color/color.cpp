#include<bits/stdc++.h>
using namespace std;
int t,n,a[30];
bool r[30];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;++i) cin>>a[i];
        int k=pow(2,n);
        for(int i=0;i<k;++i){
            int t=i,cnt=1;
            while(t){
                r[cnt]=t%2;
                t/=2;
                cnt++;
            }
            cnt=0;
            for(int i=2;i<=n;++i){
                for(int j=1;j<i;++j) if(((r[i]&&r[j])||(!r[i]&&!r[j]))&&a[i]==a[j]) cnt+=a[i];
            }
            ans=max(cnt,ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}