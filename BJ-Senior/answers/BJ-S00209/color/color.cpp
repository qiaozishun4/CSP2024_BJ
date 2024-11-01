#include<iostream>
using namespace std;
#define int long long
const int maxn=2e5+10,inf=1e17;
int t,n,a[maxn];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<1<<n;i++){
            int pre1=0,pre2=0,cnt=0;
            for(int j=n-1;j>=0;j--){
                if(i>>j&1){
                    if(pre1!=0&&a[n-pre1]==a[n-j])cnt+=a[n-j];
                    pre1=j;
                }
                else{
                    if(pre2!=0&&a[n-pre2]==a[n-j])cnt+=a[n-j];
                    pre2=j;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
    }
}