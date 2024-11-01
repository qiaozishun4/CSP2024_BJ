#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MXN=4e5+10,MXL=2e6+10;
const ll inf=1e18+10;
int T;
int n,len;
ll a[MXN];
int p[MXL];
ll qzh[MXN],f[MXL];
inline ll get_w(const int l,const int r){
    if(l>r) return 0;
    return qzh[r]-qzh[l-1];
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        len=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            len=max(len,(int)a[i]);
        }
        for(int i=1;i<=len;i++){
            p[i]=0,f[i]=-1;
        }
        ll ln=0,ls=0,ans=0;
        for(int i=1,lp=0;i<=n;i++){
            qzh[i]=qzh[i-1]+(a[i]==a[i-1])*a[i];
            lp=p[a[i]];
            if(a[i]==a[i-1]){
                ln=ls+a[i];
            }else if(lp){
                ln=f[a[i]]+get_w(lp+2,i-1)+a[i];
            }else{
                ln=-inf;
            }
            ls=max(ls,ln);
            if((i>1)&&(p[a[i-1]]==0||f[a[i-1]]<ls)){
                p[a[i-1]]=i-1;
                f[a[i-1]]=ls;
            }
            ans=max(ans,ls);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
