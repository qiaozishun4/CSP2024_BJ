#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,T,di,ai,maxdi,pi,maxpi,cnt;
long long v[100005],d[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(long long i=1;i<=T;++i){
        maxpi=0;
        cnt=0;
        cin>>n>>m>>L>>V;
        for(long long j=1;j<=n;++j){
            cin>>d[j]>>v[j]>>ai;
            maxdi=max(maxdi,di);
        }
        for(long long j=1;j<=m;++j){
            cin>>pi;
            maxpi=max(maxpi,pi);
        }
        for(long long j=1;j<=n;++j){
            if(v[j]>V&&d[j]<=maxpi&&d[j]<=L){
                cnt++;
            }
        }
        if(cnt==0){
            m++;
        }
        cout<<cnt<<" "<<m-1<<endl;
    }
    return 0;
}
