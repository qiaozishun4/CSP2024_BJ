#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
ll a[MAXN*2],b[MAXN*2],c[MAXN*2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll T,x,n,ma;
    cin>>T;
    while(T--){
        for(ll i=1;i<=2*MAXN;i++) c[i]=0;
        ma=0;
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=0;i<(1<<n);i++){
            ll m=i;
            //cout<<m<<endl;
            for(ll j=1;j<=n;j++){
                ll z=m%2;
                //cout<<x<<" ";
                m/=2;
                b[j]=z;
            }
            //cout<<endl;
            for(ll j=1;j<=n;j++){
                //cout<<j<<endl;
                x=0;
                for(ll k=1;k<j;k++){
                    if(b[j]==b[k]){
                        x=k;
                    }
                }
                //cout<<x<<endl;
                if(x==0){
                    c[j]=0;
                }
                else if(a[j]==a[x]){
                    c[j]=a[j];
                    //cout<<a[j]<<" "<<a[x]<<" "<<j<<" "<<x<<endl;
                }
            }
            //cout<<endl;
            ll sum=0;
            for(ll j=1;j<=n;j++){
                //if(c[j]!=0) cout<<j<<endl;
                sum+=c[j];
            }
            //cout<<sum<<endl;
            if(sum>ma) ma=sum;
        }
        cout<<ma<<endl;
    }
    return 0;
}