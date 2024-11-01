#include<iostream>
#include<math.h>
using namespace std;
int n,r[100186],a[100186],z[100186],cnt,mx;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        mx=max(r[i],mx);
        a[r[i]]++;
    }
    for(int i=mx;i>=1;i--){
        z[i]=z[i+1]+a[i];
    }
    for(int i=1;i<=mx;i++){
        if(a[i]>0){
            //cout<<i<<' '<<a[i]<<endl;
            cnt+=a[i];
            //cout<<cnt<<' ';
            cnt=min(cnt,z[1]-z[i]);
            //cout<<cnt<<endl;
        }
    }
    cout<<n-cnt<<endl;
    return 0;
}
