#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,a[N];
long long ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        for(int s=0;s<(1<<n);s++){
            long long kk=0;
            for(int i=1;i<=n;i++){
                int now=(s>>(i-1)&1);
                //cout<<now;
                for(int j=i-1;j>=1;j--){
                    int now1=(s>>(j-1)&1);
                    if(now1==now&&a[j]==a[i]){
                        kk+=a[i];
                    }
                    if(now1==now){
                        break;
                    }
                }
            }
            ans=max(ans,kk);
            //cout<<' '<<kk<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}